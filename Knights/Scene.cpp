#include "PCH.h"
#include "Scene.h"


Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Scene::Render()
{
	GameObject::Render();
}
