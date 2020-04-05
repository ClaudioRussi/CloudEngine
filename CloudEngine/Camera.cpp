#include "Camera.h"

Camera::Camera(glm::vec4 position)
{
	this->position = position;
}

void Camera::move(glm::mat4 translationMatrix)
{
	position = translationMatrix * position;
}

