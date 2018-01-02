#include "PCH.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider()
{
	UseMe = 0;
}

BoxCollider::~BoxCollider()
{
}

BoxCollider * BoxCollider::Create(Vector2 position, Vector2 size)
{
	auto box = new (std::nothrow) BoxCollider();
	if (box && box->InitBoxCollider(position, size))
	{
		CollisionMgr::GetInstance()->AddBoxCollider(box);
		return box;
	}

	SAFE_DELETE(box);
	return nullptr;
}

bool BoxCollider::InitBoxCollider(Vector2 position, Vector2 size)
{
	m_Position = position;
	m_Size = size;

	return true;
}

bool BoxCollider::IsCollisionWith(BoxCollider* other)
{
	//충돌 체크
	if ((IsPointContain(other)))
		return true;

	return false;
}

bool BoxCollider::IsPointContain(BoxCollider * point)
{
	auto m_Right = m_Position.x + m_Size.x;
	auto m_Bottom = m_Position.y + m_Size.y;

	auto point_Right = point->GetPosition().x + point->GetSize().x;
	auto point_Bottom = point->GetPosition().y + point->GetSize().y;

	if (m_Position.x < point_Right && m_Position.y < point_Bottom)
		if (m_Right > point->GetPosition().x && m_Bottom > point->GetPosition().y)
			return true;

	return false;
}

bool BoxCollider::IsPointInBox()
{
	auto m_Right = m_Position.x + m_Size.x;
	auto m_Bottom = m_Position.y + m_Size.y;

	int mouseX = Input::GetInstance()->GetMousePosition().x;
	int mouseY = Input::GetInstance()->GetMousePosition().y;

	if (m_Position.x <= mouseX && mouseX <= m_Right)
		if (m_Position.y <= mouseY && mouseY <= m_Bottom)
		{
			return true;
		}

	return false;
}