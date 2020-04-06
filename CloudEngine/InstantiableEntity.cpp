#include "InstantiableEntity.h"

InstantiableEntity::InstantiableEntity(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale, glm::vec4 color)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

void InstantiableEntity::process()
{
	draw();
}

void InstantiableEntity::draw()
{
}
