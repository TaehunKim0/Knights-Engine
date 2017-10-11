#pragma once
class GameObject
{
private:
	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	Matrix m_Matrix;
	Vector2 m_Postion;
	Vector2 m_Scale;
	Vector2 m_Size;

	float m_Rotation;

	std::string m_Name;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Render();

	void SetParent(GameObject* parent);
	void AddChild(GameObject* child);

	void RemoveChild(GameObject* child);
};

