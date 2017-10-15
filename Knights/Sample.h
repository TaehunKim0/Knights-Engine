#pragma once

class Man : public GameObject
{
private:
	Sprite* man;

	BoxCollider* man_box;

public:
	bool Init()
	{
		man = Sprite::Create(L"Resources/Anubis.png");

		man_box = BoxCollider::Create(m_Position, man->GetSize());

		AddChild(man_box);
		AddChild(man);

		return true;
	}

	void Update(float deltaTime)
	{
		GameObject::Update(deltaTime);
		man_box->SetPosition(m_Position);
		
	}
	void Render()
	{
		GameObject::Render();
	}

	BoxCollider* GetCollider()
	{
		return man_box;
	}
};


class Man2 : public GameObject
{
private:
	Sprite* man2;
	BoxCollider* man2_box;

public:
	bool Init()
	{
		man2 = Sprite::Create(L"Resources/Thoth.png");

		man2_box = BoxCollider::Create(m_Position, man2->GetSize());
		
		AddChild(man2_box);
		AddChild(man2);

		return true;
	}

	void Update(float deltaTime)
	{
		GameObject::Update(deltaTime);
		man2_box->SetPosition(m_Position);
	}
	void Render()
	{
		GameObject::Render();
	}

	BoxCollider* GetCollider()
	{
		return man2_box;
	}

};

class Sample : public Scene
{
private:
	Sprite*ground;
	Man* man;
	Man2* man2;

public:
	CREATE_FUNC(Sample);
	Sample();
	~Sample();

	bool Init();
	void Update(float deltaTime);
	void Render();
	void Move()
	{

		if (Input::GetInstance()->GetKeyState(VK_UP) == KeyState::Pressed)
			man->SetPosition(0.f, -10.f);

		if (Input::GetInstance()->GetKeyState(VK_DOWN) == KeyState::Pressed)
			man->SetPosition(0.f, 10.f);

		if (Input::GetInstance()->GetKeyState(VK_LEFT) == KeyState::Pressed)
			man->SetPosition(-10.f, 0.f);

		if (Input::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::Pressed)
			man->SetPosition(10.f, 0.f);

		if (Input::GetInstance()->GetKeyState('1') == KeyState::Pressed)
			GetCamera()->Translate(-10.f, 0.f);

		if (Input::GetInstance()->GetKeyState('2') == KeyState::Pressed)
			GetCamera()->Translate(10.f, 0.f);

		if (Input::GetInstance()->GetKeyState('3') == KeyState::Pressed)
			GetCamera()->Translate(0.f, -10.f);

		if (Input::GetInstance()->GetKeyState('4') == KeyState::Pressed)
			GetCamera()->Translate(0.f, 10.f);
	}
};

