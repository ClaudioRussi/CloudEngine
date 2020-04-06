#pragma once
#include "Entity.h"
class InstantiableEntity: public Entity
{
	public:
		InstantiableEntity(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale, glm::vec4 color);
		void process();
		void draw();
};

