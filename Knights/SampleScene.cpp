#include "PCH.h"
#include "SampleScene.h"


SampleScene::SampleScene()
{
}


SampleScene::~SampleScene()
{
}

bool SampleScene::Init()
{
	man = Sprite::Create(L"Resources/BackGround.png");
	manAnim = Animation::Create(20);

	manAnim->AddFrame(L"Resources/Thoth.png");
	manAnim->AddFrame(L"Resources/Anubis.png");

	manAnim->SetPosition(500.f, 500.f);

	//man->SetPosition(200.f, 200.f);

	AddChild(manAnim);
	//AddChild(man);

	return true;
}

void SampleScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
	//man->SetPosition(0.f, 10.f);
}

void SampleScene::Render()
{
	Scene::Render();
}
