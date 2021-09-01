#include <iostream>
#include <cstring>
#include <thread>
#include <vector>
#include <glm/gtc/constants.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <algorithm>



using namespace std;

GLFWwindow* window = NULL;
int width = 1000;
int height = 500;
int fwidth = width;
int fheight = height;

glm::mat4 viewMat(1.0);
glm::mat4 projMat(1.0);
vector<glm::vec3> allObjects;
vector<glm::mat4> allModles;

class camera {
private:
	glm::vec3 eye = glm::vec3(0, 0, 1);
	glm::vec3 center = glm::vec3(0, 0, 0);
	glm::vec3 up = glm::vec3(0, 1, 0);
	float fov = glm::radians(90.0f);
	float aspectRatio = ((float)fwidth) / ((float)fheight);
	float near = 0.01;
	float far = 1000.0;
public:
	camera() {
	};

	glm::mat4 getView() {
		return glm::lookAt(eye, center, up);
	};
	glm::mat4 getProj() {
		return glm::perspective (fov, aspectRatio, near, far);
	};
	void setaspectratio(float A) {
		aspectRatio = A;
	};
	void forward(float distance) {
		glm::vec3 S = center - eye;
		S = glm::normalize(S);
		S = distance * S;
		eye = S + eye;
		center = S + center;

	};
	glm::vec3 GetCenter()
	{
		return center;
	};
	void rotate(float rads) {
	
		glm::vec3 S2 = center - eye;
		S2 = glm::normalize(S2);
		glm::vec4 H = glm::vec4(S2, 0.0);
		glm::mat4 R = glm::rotate(rads, up);
		H = R * H;
		center = glm::vec3(H) + eye;

	}; 
};

struct Vertex {
	glm::vec3 pos = glm::vec3(0, 0, 0);
	glm::vec4 color = glm::vec4(1, 1, 1, 1);
	glm::vec3 normal = glm::vec3(0, 0, 0);

	Vertex() {};
	Vertex(glm::vec3 p) { pos = p; };
	Vertex(glm::vec3 p, glm::vec4 c) { pos = p; color = c; };
};

vector<Vertex> vertData;
void computeOneNormal(
	vector<Vertex>& v,
	int i1, int i2, int i3) {

	Vertex v1 = v.at(i1);
	Vertex v2 = v.at(i2);
	Vertex v3 = v.at(i3);

	glm::vec3 s1 = v2.pos - v1.pos;
	glm::vec3 s2 = v3.pos - v1.pos;
	glm::vec3 N = glm::normalize(glm::cross(s1, s2));
	// s1 x s2 = -(s2 x s1)

	v.at(i1).normal += N;
	v.at(i2).normal += N;
	v.at(i3).normal += N;
}

void computeAllNormals(
	vector<Vertex>& v,
	vector<GLuint>& ind) {

	for (int i = 0; i < ind.size(); i += 3) {
		computeOneNormal(
			v,
			ind.at(i),
			ind.at(i + 1),
			ind.at(i + 2));
	}

	for (int k = 0; k < v.size(); k++) {
		v.at(k).normal = glm::normalize(v.at(k).normal);
	}
}

GLint modelMatLoc = -1;
GLint viewMatLoc = -1;
GLint projMatLoc = -1;
GLint normMatLoc = -1;
GLint lightcolorLoc = -1;
GLint lightPosLoc = -1;

camera Allcamera[2];
float playerspeed = 0.1f;
string vertCode = R"(
#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec4 color;
layout(location=2) in vec3 normal;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;
uniform mat3 normMat;

out vec4 interPos;
out vec4 interColor;
out vec3 interNormal;

void main() {
	vec4 pos = vec4(position, 1.0);
	vec4 vpos = viewMat*modelMat*pos;
	interPos = vpos;
	gl_Position = projMat*vpos;

	interColor = color;

	interNormal = normMat*normal;
} 
)";

string fragCode = R"(
#version 330 core
layout(location=0) out vec4 out_color;

in vec4 interColor;
in vec4 interPos;
in vec3 interNormal;

struct PointLight {
	vec4 pos;
	vec4 color;
};
uniform PointLight light;

void main() {
//	out_color = vec4(1.0, 1.0, 0.0, 1.0);

	vec3 L = vec3(light.pos - interPos);
	vec3 N = normalize(interNormal);
	L = normalize(L);
	float diffuse = max(0, dot(N, L));
	vec3 diffuseColor = diffuse*vec3(light.color)*vec3(interColor);
	out_color = vec4(diffuseColor, 1.0);
	//out_color = vec4(N,1);

	vec3 V = normalize(vec3(-interPos));
	vec3 H = normalize(V+L);
	float shine = 100.0f; 
	float spec = pow(max(0,dot(N,H)),shine);
    vec3 specularColor = diffuse * spec * vec3(light.color);
    out_color = vec4(diffuseColor + specularColor,1);

}
)";

GLuint VBO = 0;
GLuint VAO = 0;
GLuint EBO = 0;

void checkShaderCompile(GLuint shaderID, string shaderName) {

	std::cout << "*************************************" << std::endl;
	std::cout << "Checking: " << shaderName << std::endl;

	GLint resultGL = GL_FALSE;
	int infoLogLength;

	// Get the compilation status
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &resultGL);

	// Get how long the info message is
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

	// Make a "string" that has the right length
	std::vector<char> shaderErrorMessage(std::max(infoLogLength, int(1)));

	// Get the actual shader message
	glGetShaderInfoLog(shaderID, infoLogLength, NULL, &shaderErrorMessage[0]);

	// Is this OK?
	if (!resultGL || shaderID == 0) {
		// Print error message
		std::cerr << &shaderErrorMessage[0] << std::endl;
		std::cerr << "Error compiling " << shaderName << std::endl;
		throw std::runtime_error("Error compiling shader.");
	}

	std::cout << shaderName << " compiled successfully." << std::endl;
}

void checkShaderProgramLink(GLuint programID) {

	std::cout << "*************************************" << std::endl;
	std::cout << "Checking shader program linking..." << std::endl;

	GLint resultGL = GL_FALSE;
	int infoLogLength;

	// Get linking status
	glGetProgramiv(programID, GL_LINK_STATUS, &resultGL);

	// Get how long the info message is
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

	// Make a "string" that has the right length
	std::vector<char> programErrorMessage(std::max(infoLogLength, int(1)));

	// Get the actual linker message
	glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);

	// All good?
	if (!resultGL || programID == 0) {
		// Print the error message
		std::cerr << &programErrorMessage[0] << std::endl;
		std::cerr << "Error linking shaders." << std::endl;
		throw std::runtime_error("Error linking shaders.");
	}

	std::cout << "Shader program linked successfully." << std::endl;
	std::cout << "*************************************" << std::endl;
}


static void error_callback(int error, const char* desc) {
	cerr << "ERROR " << error << ": " << desc << endl;
}

static void key_callback(
	GLFWwindow* window, int key,
	int scancode, int action, int mods) {

	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		switch (key) {
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		case GLFW_KEY_Q:
			for (int i = 0; i < allObjects.size(); i++)
				{
					allModles.at(i) = glm::translate(allObjects.at(i)) * glm::rotate(glm::radians(5.0f),glm::vec3(0,0,1)) * glm::translate(-(allObjects.at(i)))* allModles.at(i);
				}
			break;
		case GLFW_KEY_E:
			for (int i = 0; i < allObjects.size(); i++)
			{
				allModles.at(i) = glm::translate(allObjects.at(i)) * glm::rotate(glm::radians(-5.0f), glm::vec3(0, 0, 1)) * glm::translate(-(allObjects.at(i))) * allModles.at(i);
			}			
			break;
		case GLFW_KEY_A:
			Allcamera[0].rotate(glm::radians(5.0f));
			break;
		case GLFW_KEY_D:
			Allcamera[0].rotate(glm::radians(-5.0f));
			break;
		case GLFW_KEY_W:
			Allcamera[0].forward(playerspeed);
			break;
		case GLFW_KEY_S:
			Allcamera[0].forward(-playerspeed);
			break;
		case GLFW_KEY_J:
			Allcamera[1].rotate(glm::radians(5.0f));
			break;
		case GLFW_KEY_L:
			Allcamera[1].rotate(glm::radians(-5.0f));
			break;
		case GLFW_KEY_I:
			Allcamera[1].forward(playerspeed);
			break;
		case GLFW_KEY_K:
			Allcamera[1].forward(-playerspeed);
			break;
		}
	}
}

int main(int argc, char** argv) {
	cout << "BEGIN!!!!" << endl;

	if (argc < 3) {
		cout << "ERROR: ARGC LESS THEN 3!";
		exit(1);
	}
	int sides = atoi(argv[1]);

	if (sides < 3) {
		cout << "ERROR: SIDES IS LESS THAN 3!";
		exit(1);
	}

	int grid_sides = atoi(argv[2]);

	if (grid_sides < 2) {
		cout << "ERROR: GRID SIDES IS LESS THAN 2!";
		exit(1);
	}

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(
		width, height, "BEHOLD!",
		NULL, NULL);

	if (!window) {
		cerr << "ERROR: Window null!" << endl;
		glfwTerminate();
		exit(1);
	}

	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	glClearColor(0.0f, 0.7f, 0.0f, 1.0f);

	glewExperimental = true;

	GLenum err = glewInit();

	if (GLEW_OK != err) {
		cout << "GLEW ERROR: ";
		cout << glewGetErrorString(err) << endl;
		glfwTerminate();
		exit(1);
	}

	GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);

	char const* vertPtr = vertCode.c_str();
	char const* fragPtr = fragCode.c_str();
	glShaderSource(vertID, 1, &vertPtr, NULL);
	glShaderSource(fragID, 1, &fragPtr, NULL);
	glCompileShader(vertID);
	glCompileShader(fragID);
	checkShaderCompile(vertID, "VERTEX SHADER");
	checkShaderCompile(fragID, "FRAGMENT SHADER");
	GLuint progID = glCreateProgram();
	glAttachShader(progID, vertID);
	glAttachShader(progID, fragID);
	glLinkProgram(progID);
	checkShaderProgramLink(progID);
	glDeleteShader(vertID);
	glDeleteShader(fragID);

	modelMatLoc = glGetUniformLocation(progID, "modelMat");
	viewMatLoc = glGetUniformLocation(progID, "viewMat");
	projMatLoc = glGetUniformLocation(progID, "projMat");
	normMatLoc = glGetUniformLocation(progID, "normMat");
	lightcolorLoc = glGetUniformLocation(progID, "light.color");
	lightPosLoc = glGetUniformLocation(progID, "light.pos");

	double distance = 2.0f / (float)(grid_sides - 1);

	for (int i = 0; i < grid_sides; i++) {
		float y = -1 + distance * i;
		for (int j = 0; j < grid_sides; j++) {
			float x = -1 + distance * j;
		 glm::vec3 p = glm::vec3(x, y, 0);
			 allObjects.push_back(p);
			 glm::mat4 m = glm::translate(p);
			 allModles.push_back(m);
		}
	}

	vector<Vertex> vertOnly = {};
	double radius = 0.4 * (distance);
	 Vertex v0;
	 v0.pos = glm::vec3(0, 0, radius);
	 v0.color = glm::vec4(1, 0, 0, 1);
	 vertOnly.push_back(v0);
//	vertOnly.push_back(0);
//	vertOnly.push_back(0);
//	vertOnly.push_back(radius);

	for (int i = 0; i < sides; i++) {
		double PI = glm::pi<float>();
		double radians = 2 * PI;
		double radian_angle = (radians / sides) * i;
		double x = radius * cos(radian_angle);
		double y = radius * sin(radian_angle);
		double z = 0.0;
		Vertex v1;
		v1.pos = glm::vec3(x,y,z);
		v1.color = glm::vec4(1, 0, 0, 1);
		vertOnly.push_back(v1);
	}
	/*
	for (int i = 0; i < (sides - 1); i++) {
		indices.push_back((i * 2));
		indices.push_back((i * 2 + 1));
		indices.push_back((i * 2 + 2));

		indices.push_back((i * 2 + 1));
		indices.push_back((i * 2 + 3));
		indices.push_back((i * 2 + 2));
	}
*/
	vector<GLuint> indices = {};
	for (int n = 1; n <= sides; n++) {
		if (n != sides) {
			int r = 0;
			int g = n;
			int b = (n + 1);
			indices.push_back(r);
			indices.push_back(g);
			indices.push_back(b);
		}
		else {
			indices.push_back(0);
			indices.push_back(sides);
			indices.push_back(1);
		}
	}

	computeAllNormals(vertOnly, indices);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(Vertex) * vertOnly.size(),
		vertOnly.data(),
		GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		indices.size() * sizeof(GLuint),
		indices.data(),
		GL_STATIC_DRAW);
	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		//cout << "Rendering..." << endl;

		glfwGetFramebufferSize(window, &fwidth, &fheight);
		int halfWidth = width / 2;
		float aspectRatio = 1.0;
		if (halfWidth>0 && fheight > 0){
			aspectRatio = ((float)halfWidth) / ((float)fheight);
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for(int c=0; c<2; c++){
			glViewport(halfWidth*c, 0, halfWidth, fheight);
			Allcamera[c].setaspectratio(aspectRatio);
			// Drawing stuff goes here
			glUseProgram(progID);
			glBindVertexArray(VAO);
			glUniformMatrix4fv(
				viewMatLoc, 1, GL_FALSE,
				glm::value_ptr(Allcamera[c].getView()));
			glUniformMatrix4fv(
				projMatLoc, 1, GL_FALSE,
				glm::value_ptr(Allcamera[c].getProj()));

			for (int i = 0; i < allModles.size(); i++) {
				glUniformMatrix4fv(
					modelMatLoc, 1, GL_FALSE,
					glm::value_ptr(allModles.at(i)));

				glm::mat3 normMat = glm::transpose(glm::inverse(glm::mat3(Allcamera[c].getView()* allModles.at(i))));
				glUniformMatrix3fv(
					normMatLoc, 1, GL_FALSE,
					glm::value_ptr(normMat));

				glm::vec4 viewLight = Allcamera[c].getView() * glm::vec4(Allcamera[1].GetCenter(),1);
				glUniform4fv(lightPosLoc, 1, glm::value_ptr(viewLight));
				glUniform4fv(lightcolorLoc, 1, glm::value_ptr(glm::vec4(1,1,1,1)));

				//glDrawArrays(GL_TRIANGLES, 0, vcnt);
				glDrawElements(GL_TRIANGLES,
					indices.size(),
					GL_UNSIGNED_INT,
					(void*)0);
			}
			glBindVertexArray(0);
			//Set the appropriate model matrix.
			glUseProgram(0);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
		std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &EBO);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAO);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBO);

	glUseProgram(0);
	glDeleteProgram(progID);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
