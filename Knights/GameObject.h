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

	//Vector2 AnchorPoint; //�Է¹��� AnchorPoint
	Vector2 m_AnchorPoint; //�� ����� ���� AnchorPoint�� �ٲ�� ������ ����� ���� �ٲ� ��Ŀ����Ʈ

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

