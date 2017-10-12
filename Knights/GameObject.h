#pragma once
class GameObject
{
protected:
	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	Matrix m_Matrix;
	Vector2 m_Position;
	Vector2 m_Scale;
	Vector2 m_Size;

	//Vector2 AnchorPoint; //입력받을 AnchorPoint
	Vector2 m_AnchorPoint; //내 사이즈에 따라 AnchorPoint는 바뀌기 때문에 사이즈에 따라 바뀐 앵커포인트

	float m_Rotation;

	std::string m_Name;

	bool m_Visible;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Render();

	void SetParent(GameObject* parent);
	void AddChild(GameObject* child);

	void RemoveChild(GameObject* child);
};

