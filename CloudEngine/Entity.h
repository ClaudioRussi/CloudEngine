#pragma once
#include <glm/glm/glm.hpp>
class Entity
{
	public:
		virtual void process() = 0;

	protected:
		glm::vec4 position;
		glm::vec4 rotation;
		glm::vec4 scale;

};

