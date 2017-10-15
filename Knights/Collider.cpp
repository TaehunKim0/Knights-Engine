#include "PCH.h"
#include "Collider.h"


Collider::Collider()
	: m_OffSet(0.f, 0.f)
{
}


Collider::~Collider()
{
}

void Collider::SetOffSet(Vector2 offset)
{
	m_OffSet = offset;
}

void Collider::Update(float deltaTime)
{
	m_Position = m_Parent->GetPosition();
}
