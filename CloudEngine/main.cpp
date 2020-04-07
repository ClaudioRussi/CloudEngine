#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm/glm.hpp>
#include <glm/glm/matrix.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include "SquareShape.h"
#include "StateManager.h"

struct Settings {
	int screenWidth;
	int screenHeight;
};

GLFWwindow* initWindow();
void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
void CalculateFrameRate(float time);


Settings settings;

int main() {

	settings.screenWidth = 800;
	settings.screenHeight = 600;
	StateManager state = StateManager();
	GLFWwindow* window = initWindow();
	Camera cam = Camera(glm::vec4(0, 0, 0, 1));
	SquareShape shape = SquareShape(glm::vec4(0, 0, 0, 1), glm::vec4(0, 0, 0, 0), glm::vec4(1, 1, 1, 1), glm::vec4(100, 0, 0, 0));
	shape.attachTexture("./container2.png");
	SquareShape shape2 = SquareShape(glm::vec4(1.5, 1.5, 0, 1), glm::vec4(0, 0, 0, 0), glm::vec4(1, 1, 1, 1), glm::vec4(100, 0, 0, 0));

	state.addEntity(&shape);
	int frameCounter;
	frameCounter = 0;

	while (!glfwWindowShouldClose(window)) {
		//CalculateFrameRate(glfwGetTime());
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		state.processEntities(glfwGetTime());
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

	GLFWwindow* window = glfwCreateWindow(settings.screenWidth, settings.screenHeight, "Cloud Engine", NULL, NULL);
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

void CalculateFrameRate(float time)
{
	static float framesPerSecond = 0.0f;
	static int fps;
	static float lastTime = 0.0f;
	float currentTime = time * 0.001f;
	++framesPerSecond;
	std::cout << "Current Frames Per Second: %d\n\n" << fps << std::endl;
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		fps = (int)framesPerSecond;
		framesPerSecond = 0;
	}
}
