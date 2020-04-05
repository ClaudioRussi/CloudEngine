#pragma once
#include <glm/glm/glm.hpp>
#include <glm/glm/matrix.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.h"

class SquareShape
{
	
	public:
		//This should be called every frame
		void Draw();
		void Move();
		SquareShape(glm::vec4 position, glm::vec4 color);
	private:
		glm::vec4 position;
		float speed = 0.001;
		glm::vec4 color;
		unsigned int VBO, VAO, EBO;
		Shader shader;
};

