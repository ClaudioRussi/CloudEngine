#include <glm/glm/glm.hpp>
class Entity
{
	public:
		Entity(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale);

	protected:
		glm::vec4 position;
		glm::vec4 rotation;
		glm::vec4 scale;

};

