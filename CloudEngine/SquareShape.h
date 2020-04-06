#pragma once
#include <glm/glm/glm.hpp>
#include <glm/glm/matrix.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.h"
#include "Camera.h"
#include "stb_image.h"
#include "Entity.h"

class SquareShape: public Entity
{
	
	public:
		SquareShape(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale, glm::vec4 color);
		//This should be called every frame
		void draw();
		void process();
		void move();
		void attachCamera(Camera camera);
		void attachTexture(const char* path);
	private:
		float speed = 0.001f;
		glm::vec4 color;
		unsigned int VBO, VAO, EBO;
		Shader shader;
		Camera camera;
		bool hasCamera = false;
		unsigned int texture;
		bool useTexture = false;
};

