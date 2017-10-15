#pragma once
class CircleCollider : public Collider
{
private:
	float m_Raidus;


public:
	CircleCollider();
	~CircleCollider();

	static CircleCollider* Create(float radius);
	bool InitCircleCollider(float radius);

};

