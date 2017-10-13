#include "PCH.h"
#include "Sample.h"


Sample::Sample()
{
}


Sample::~Sample()
{
}

bool Sample::Init()
{
	Scene::Init();
	man = Sprite::Create(L"Resources/Anubis.png");

	man->SetPosition(500.f, 500.f);
	AddChild(man);

	return true;
}

void Sample::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState(VK_UP) == KeyState::Pressed)
		man->SetPosition(0.f, -10.f);

	if (Input::GetInstance()->GetKeyState(VK_DOWN) == KeyState::Pressed)
		man->SetPosition(0.f, 10.f);

	if (Input::GetInstance()->GetKeyState(VK_LEFT) == KeyState::Pressed)
		man->SetPosition(-10.f, 0.f);

	if (Input::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::Pressed)
		man->SetPosition(10.f, 0.f);

	if (Input::GetInstance()->GetMouseState(MouseButton::Left) == KeyState::Up)
		GetCamera()->Translate(0.f, 10.f);

	if (Input::GetInstance()->GetMouseState(MouseButton::Right) == KeyState::Up)
		GetCamera()->Translate(10.f, 0.f);


}

void Sample::Render()
{
	Scene::Render();
}