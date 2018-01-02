#pragma once
enum class Tag
{
	None = 0,
	Player = 1,
	Enemy,
	Structure
};

enum class Direction
{
	Left = 1,
	Right,
	Up,
	Down
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
	Direction m_Direction;

	int m_ZOrder;

	float m_Rotation;

	std::wstring m_Name;

	bool m_Visible;

	bool UsingParentMatrix;
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Release();

	void MatrixUsing(bool a) { UsingParentMatrix = a; }
	void SortZOrder();
	void SetZOrder(int z) { m_ZOrder = z; }
	int GetZOrder() { return m_ZOrder; }
	GameObject* GetParent();
	void SetParent(GameObject* parent);
	void AddChild(GameObject* child);

	void RemoveChild(GameObject* child);
	virtual void OnCollision(GameObject* other) {};

	virtual void Destroy()
	 {
		if (m_Parent)
		{
			m_Parent->DestroyList.push_back(this);
		}

		printf("Object Destroy : %s\n", m_Name.c_str());

	}

public:
	void SetTag(Tag tag)
	{
		m_Tag = tag;
	}

	void SetDirection(Direction direction)
	{
		m_Direction = direction;
	}

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
		if (m_Parent == nullptr)
			return Tag::None;

		return m_Tag;
	}

	Direction GetDirection()
	{
		return m_Direction;
	}


public:
	void SetPosition(float x, float y);
	void SetPosition(Vector2 pos);

	void PositionSet(float x, float y) { m_Position.x = x; m_Position.y = y; }

	void SetScale(Vector2 scale);
	void SetRotation(float r);
	void SetVisible(bool a)
	{
		m_Visible = a;
	}
};

