#pragma once
class CollisionMgr : public Singleton<CollisionMgr>, public GameObject
{
private:
	std::vector<BoxCollider*> m_BoxColliderList;

public:
	CollisionMgr();
	~CollisionMgr();

	bool Init();
	void Update(float deltatime);
	void Render();

public:
	void AddBoxCollider(BoxCollider* box);
	bool IsPointInBox(Vector2 size, Vector2 position);
	void Destroy(BoxCollider* child);
};



