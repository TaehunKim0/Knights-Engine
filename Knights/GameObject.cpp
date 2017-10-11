#include "PCH.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	//
}

void GameObject::Update(float deltaTime)
{
	//Children Update
}

void GameObject::Render()
{
	//Children Render
}

void GameObject::SetParent(GameObject * parent)
{
	if (parent == nullptr)
		return;

	m_Parent = parent;
}

void GameObject::AddChild(GameObject * child)
{
	//AddChild in Children
}

void GameObject::RemoveChild(GameObject * child)
{
	//RemoveChild in Children
}
