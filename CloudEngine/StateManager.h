#pragma once
#include<vector>
#include "InstantiableEntity.h"
#include "Camera.h"
using namespace std;
class StateManager
{
	public:
		StateManager();
		void addEntity(Entity* entity);
		void addInstantiableEntity(InstantiableEntity* entity);
		void processEntities(float time);
		void destroyEntity(Entity* entity);
		void destroyInstantiableEntity(InstantiableEntity* entity);
		void setMainCamera(Camera* cam);

	protected:
	vector<InstantiableEntity*> instantiableEntities;
	vector<Entity*> entities;
	Camera* mainCamera;
	float lastTime;
};

