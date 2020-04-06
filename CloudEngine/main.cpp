#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm/glm.hpp>
#include <glm/glm/matrix.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include "SquareShape.h"
#include "StateManager.h"

GLFWwindow* initWindow();
void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
	StateManager state = StateManager();
	GLFWwindow* window = initWindow();
	Camera cam = Camera(glm::vec4(0, 0, 0, 1));
	SquareShape shape = SquareShape(glm::vec4(0, 0, 0, 1), glm::vec4(0, 0, 0, 0), glm::vec4(1, 1, 1, 1), glm::vec4(100, 0, 0, 0));
	shape.attachTexture("./container2.png");
	SquareShape shape2 = SquareShape(glm::vec4(1.5, 1.5, 0, 1), glm::vec4(0, 0, 0, 0), glm::vec4(1, 1, 1, 1), glm::vec4(100, 0, 0, 0));

	state.addEntity(&shape);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		state.processEntities();
		shape2.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

GLFWwindow* initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Cloud Engine", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	return window;
}

//CALLBACKS
void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

