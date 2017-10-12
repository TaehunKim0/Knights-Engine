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

	AddChild(man);

	return true;
}

void SampleScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void SampleScene::Render()
{
	Scene::Render();
}
