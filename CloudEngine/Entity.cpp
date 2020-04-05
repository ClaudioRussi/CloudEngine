#include "Entity.h"

Entity::Entity(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}
