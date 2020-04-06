#pragma once
#include<vector>
#include "InstantiableEntity.h"
using namespace std;
class StateManager
{
	public:
		StateManager();
		void addEntity(Entity* entity);
		void addInstantiableEntity(InstantiableEntity* entity);
		void processEntities();
		void destroyEntity(Entity* entity);
		void destroyInstantiableEntity(InstantiableEntity* entity);

	protected:
	vector<InstantiableEntity*> instantiableEntities;
	vector<Entity*> entities;
};

