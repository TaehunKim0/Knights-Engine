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
	man = Sprite::Create(L"Resources/Anubis.png");

	man->SetPosition(500.f, 500.f);
	AddChild(man);

	return true;
}

void Sample::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState(VK_SPACE) == KeyState::Up)
		man->SetPosition(0.f, 10.f);

	if (Input::GetInstance()->GetMouseState(MouseButton::Left) == KeyState::Up)
		man->SetPosition(10.f, 0.f);

}

void Sample::Render()
{
	Scene::Render();
}