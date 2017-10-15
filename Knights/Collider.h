#pragma once
class Collider : public GameObject
{
protected:
	Vector2 m_OffSet;

public:
	Collider();
	virtual ~Collider();

	void SetOffSet(Vector2 offset);
	void Update(float deltaTime);

};