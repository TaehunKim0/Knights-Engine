#include "PCH.h"
#include "Director.h"


Director::Director()
	:CurrentScene(nullptr)
{
}

Director::~Director()
{
	
}

void Director::SetScene(Scene * scene)
{
	if (CurrentScene)
		SAFE_DELETE(CurrentScene);

	CurrentScene = scene;
}

void Director::Update(float deltaTime)
{
	if (CurrentScene)
		CurrentScene->Update(deltaTime);
	else
		return;
}

void Director::Render()
{
	if (CurrentScene)
		CurrentScene->Render();
	else
		return;
}
