#include "PCH.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}

CollisionMgr::~CollisionMgr()
{
}

void CollisionMgr::Update(float deltatime)
{
	GameObject::Update(deltatime);

	for each(auto box1 in m_BoxColliderList)
	{
		for each(auto box2 in m_BoxColliderList)
		{
			if (box1 != box2)
			{
				if (box1->GetParent()->GetTag() != box2->GetParent()->GetTag())
				{
					if (box1->IsCollisionWith(box2))
					{
						box1->GetParent()->OnCollision(box2->GetParent());
						box2->GetParent()->OnCollision(box1->GetParent());
					}
				}
			}
		}
	}

}

void CollisionMgr::Render()
{
	GameObject::Render();
}

void CollisionMgr::AddBoxCollider(BoxCollider * box)
{
	m_BoxColliderList.push_back(box);

}
