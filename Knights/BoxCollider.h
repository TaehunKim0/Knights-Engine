#pragma once
class BoxCollider : public Collider
{
private:


public:
	BoxCollider();
	~BoxCollider();

	static BoxCollider* Create(Vector2 position, Vector2 size);
	bool InitBoxCollider(Vector2 position, Vector2 size);

public:
	bool IsCollisionWith(BoxCollider* other);
	bool IsPointContain(BoxCollider * point);
};

