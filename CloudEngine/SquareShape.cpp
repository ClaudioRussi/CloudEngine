#include "SquareShape.h"
#include <vector>
#include <glm/glm/gtx/string_cast.hpp>

SquareShape::SquareShape(glm::vec4 position, glm::vec4 color)
{
	this->position = position;
	this->color = color;
	float vertices[] = {
	 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{
		std::cout << "ERROR: " << err << std::endl;
	}

	shader = Shader("./shape.vs", "./shape.fs");
}

void SquareShape::Draw()
{
	shader.Use();
	shader.setVec4("Position", position.x, position.y, position.z, position.w);
	glBindVertexArray(VAO);
	//glDrawElements(GL_TRIANGLES, 0, 20);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	
}

void SquareShape::Move()
{
	GLFWwindow* window = glfwGetCurrentContext();
	glm::mat4 translationMatrix = glm::mat4(1.0f);
	glm::vec3 movementVector = glm::vec3(0.0f);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		movementVector.y += 1;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		movementVector.y -= 1;
		
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		movementVector.x += 1;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		movementVector.x -= 1;
	}
	if (movementVector != glm::vec3()) {
		movementVector = glm::clamp(movementVector, -1.0f, 1.0f) * speed;
		translationMatrix = glm::translate(translationMatrix, movementVector);
		position = translationMatrix * position;
	}
	
}


