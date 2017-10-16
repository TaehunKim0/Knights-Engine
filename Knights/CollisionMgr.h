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
	void Destroy(BoxCollider* child);
};