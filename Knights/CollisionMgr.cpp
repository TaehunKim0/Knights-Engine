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

bool CollisionMgr::IsPointInBox(Vector2 size, Vector2 position)
{
	auto m_Right = position.x + size.x;
	auto m_Bottom = position.y + size.y;

	int mouseX = Input::GetInstance()->GetMousePosition().x;
	int mouseY = Input::GetInstance()->GetMousePosition().y;

	if (position.x <= mouseX && mouseX <= m_Right)
		if (position.y <= mouseY && mouseY <= m_Bottom)
		{
			return true;
		}

	return false;
}

void CollisionMgr::Destroy(BoxCollider * child)
{
	auto iterator = std::find(std::begin(m_BoxColliderList), std::end(m_BoxColliderList), child);
	if (iterator != m_BoxColliderList.end())
	{
		m_BoxColliderList.erase(iterator); //Collider 에서도 제거
	}
}

