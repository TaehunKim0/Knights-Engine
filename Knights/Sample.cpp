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
	ground = Sprite::Create(L"Resources/Map/Stage1.png");

	man = new Man();
	man->Init();

	man2 = new Man2();
	man2->Init();

	man2->SetPosition(200.f, 200.f);

	//AddChild(ground);
	AddChild(man);
	AddChild(man2);


	return true;
}

void Sample::Update(float deltaTime)
{
	Scene::Update(deltaTime);
	Move();
	if ((man->GetCollider()->IsCollisionWith(man2->GetCollider())))
		printf("Coolide\n");

	printf("%f, %f \n", man->GetPosition().x, man->GetPosition().y);
	printf("%f, %f \n", man2->GetPosition().x, man2->GetPosition().y);

}

void Sample::Render()
{
	Scene::Render();
}