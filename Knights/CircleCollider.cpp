#include "PCH.h"
#include "CircleCollider.h"


CircleCollider::CircleCollider()
{
}

CircleCollider::~CircleCollider()
{
}

CircleCollider * CircleCollider::Create(float radius)
{
	auto circle = new (std::nothrow) CircleCollider();
	if (circle && circle->InitCircleCollider(radius))
	{
		return circle;
	}

	SAFE_DELETE(circle);
	return nullptr;
}

bool CircleCollider::InitCircleCollider(float radius)
{
	m_Raidus = radius;

	return true;
}
