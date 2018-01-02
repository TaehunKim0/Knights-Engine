#include "PCH.h"
#include "Scene.h"


Scene::Scene()
	:m_Camera(nullptr)
{
}

Scene::~Scene()
{
}
void Scene::Release()
{
	GameObject::Release();
}

bool Scene::Init()
{
	m_Camera = Camera::Create(this);
	AddChild(m_Camera);

	return true;
}

void Scene::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Scene::Render()
{
	GameObject::Render();
}
