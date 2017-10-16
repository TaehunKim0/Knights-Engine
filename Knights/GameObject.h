#pragma once
enum class Tag
{
	Player = 1,
	Enemy
};
class BoxCollider;
class GameObject
{
protected:
	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;
	std::vector<GameObject*> DestroyList;
	
	Matrix m_Matrix;
	Vector2 m_Position;
	Vector2 m_Scale;
	Vector2 m_Size;

	BoxCollider* m_Collision;

	//Vector2 AnchorPoint; //입력받을 AnchorPoint
	Vector2 m_AnchorPoint; //내 사이즈에 따라 AnchorPoint는 바뀌기 때문에 사이즈에 따라 바뀐 앵커포인트
	Tag m_Tag;

	float m_Rotation;

	std::wstring m_Name;

	bool m_Visible;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Release();

	GameObject* GetParent();
	void SetParent(GameObject* parent);
	void AddChild(GameObject* child);

	void RemoveChild(GameObject* child);
	virtual void OnCollision(GameObject* other) {};

	virtual void Destroy()
	 {
		if (m_Parent)
			m_Parent->DestroyList.push_back(this);

		printf("Object Destroy : %s\n", m_Name.c_str());

	}

public:
	Vector2 GetPosition()
	{
		return m_Position;
	}

	Vector2 GetScale()
	{
		return m_Scale;
	}

	float GetRotation()
	{
		return m_Rotation;
	}

	Vector2 GetSize()
	{
		return m_Size;
	}

	Tag GetTag()
	{
		return m_Tag;
	}

public:
	void SetPosition(float x, float y);
	void SetPosition(Vector2 pos);
	void SetScale(Vector2 scale);
	void SetRotation(float r);

};

