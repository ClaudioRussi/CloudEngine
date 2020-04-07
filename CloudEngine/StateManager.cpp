#include "StateManager.h"

StateManager::StateManager()
{
}

void StateManager::addEntity(Entity* entity)
{
	entities.push_back(entity);
}

void StateManager::addInstantiableEntity(InstantiableEntity* entity)
{
	instantiableEntities.push_back(entity);
}

void StateManager::processEntities(float time)
{
	for (Entity* ent : entities) {
		ent->process();
	}
	for (InstantiableEntity* insEnt : instantiableEntities) {
		insEnt->process();
	}
}

void StateManager::destroyEntity(Entity* entity)
{
	entities.erase(std::find(entities.begin(), entities.end(), entity));
}

void StateManager::destroyInstantiableEntity(InstantiableEntity* entity)
{
	instantiableEntities.erase(std::find(instantiableEntities.begin(), instantiableEntities.end(), entity));
}

void StateManager::setMainCamera(Camera* cam)
{
	mainCamera = cam;
}
