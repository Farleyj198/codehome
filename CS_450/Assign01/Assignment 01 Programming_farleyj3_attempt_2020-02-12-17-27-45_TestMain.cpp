#include <iostream>
#include <cstring>
#include <thread>
#include <vector>
#include <glm/gtc/constants.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;

GLFWwindow* window = NULL;
int width = 500;
int height = 500;
int fwidth = width;
int fheight = height;

string vertCode = R"(
#version 330 core

layout(location=0) in vec3 position;

void main() {
	gl_Position = vec4(position, 1.0);
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

static void error_callback(int error, const char* desc) {
	cerr << "ERROR " << error << ": " << desc << endl;
}

int main(int argc, char** argv) {
	cout << "BEGIN!!!!" << endl;

	if (argc < 2) {
		cout << "ERROR: ARGC LESS THEN 2!";
		exit(1);
}
	int sides = atoi(argv[1]);

	if (sides < 3) {
		cout << "ERROR: SIDES IS LESS THAN 3!";
		exit(1);
	}

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		exit(1);
	}

	window = glfwCreateWindow(
		width, height, "BEHOLD!",
		NULL, NULL);

	if (!window) {
		cerr << "ERROR: Window null!" << endl;
		glfwTerminate();
		exit(1);
	}

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
	
	glGetError();

	GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);

	char const* vertPtr = vertCode.c_str();
	char const* fragPtr = fragCode.c_str();
	glShaderSource(vertID, 1, &vertPtr, NULL);
	glShaderSource(fragID, 1, &fragPtr, NULL);
	glCompileShader(vertID);
	glCompileShader(fragID);
	GLuint progID = glCreateProgram();
	glAttachShader(progID, vertID);
	glAttachShader(progID, fragID);
	glLinkProgram(progID);
	glDeleteShader(vertID);
	glDeleteShader(fragID);

	vector<GLfloat> vertOnly = {};
				for (int i = 0; i < sides; i++)
				{
					double PI = glm::pi<float>();
					double radius = 0.5;
					double radians = 2 * PI;
					double radian_angle = (radians / sides) * i;
					double x = radius * cos(radian_angle);
					double y = radius * sin(radian_angle);
					double z = 0.0;
					vertOnly.push_back(x);
					vertOnly.push_back(y);
					vertOnly.push_back (z);
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
		//glDrawArrays(GL_TRIANGLES, 0, vcnt);
		glDrawElements(GL_TRIANGLES,
			indices.size(),
			GL_UNSIGNED_INT,
			(void*)0);
		glBindVertexArray(0);
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
