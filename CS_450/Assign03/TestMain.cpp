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
int width = 500;
int height = 500;
int fwidth = width;
int fheight = height;

vector<glm::vec3> allObjects;
vector<glm::mat4> allModles;

GLint modelMatLoc = -1;

string vertCode = R"(
#version 330 core

uniform mat4 modelMat;

layout(location=0) in vec3 position;

void main() {
	gl_Position = modelMat * vec4(position, 1.0);
} 
)";

string fragCode = R"(
#version 330 core
layout(location=0) out vec4 out_color;
void main() {
	out_color = vec4(1.0, 1.0, 0.0, 1.0);
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
			}			break;
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
	glGetError();

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

	vector<GLfloat> vertOnly = {};
	for (int i = 0; i < sides; i++)
	{
		double PI = glm::pi<float>();
		double radius = 0.4 *(distance);
		double radians = 2 * PI;
		double radian_angle = (radians / sides) * i;
		double x = radius * cos(radian_angle);
		double y = radius * sin(radian_angle);
		double z = 0.0;
		vertOnly.push_back(x);
		vertOnly.push_back(y);
		vertOnly.push_back(z);
	}

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

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(GLfloat) * vertOnly.size(),
		vertOnly.data(),
		GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(
		0, 3, GL_FLOAT,
		GL_FALSE,
		3 * sizeof(float),
		0);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		indices.size() * sizeof(GLuint),
		indices.data(),
		GL_STATIC_DRAW);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)) {
		//cout << "Rendering..." << endl;
		glfwGetFramebufferSize(window, &fwidth, &fheight);
		glViewport(0, 0, fwidth, fheight);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Drawing stuff goes here
		glUseProgram(progID);
		glBindVertexArray(VAO);
		for (int i = 0; i < allModles.size(); i++) {
			glUniformMatrix4fv(
				modelMatLoc, 1, GL_FALSE,
				glm::value_ptr(allModles.at(i)));

			//glDrawArrays(GL_TRIANGLES, 0, vcnt);
			glDrawElements(GL_TRIANGLES,
				indices.size(),
				GL_UNSIGNED_INT,
				(void*)0);

		}
		glBindVertexArray(0);
		//Set the appropriate model matrix.
		glUseProgram(0);

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
