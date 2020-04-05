#pragma once

#include <glm/glm/glm.hpp>

class Camera
{
	public:
		Camera(glm::vec4 position);
		Camera() = default;

		void move(glm::mat4 translationMatrix);

	private:
		glm::vec4 position;
};

