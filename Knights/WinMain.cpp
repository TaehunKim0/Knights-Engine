#include"PCH.h"
#include"SampleScene.h"
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Application* app = Application::GetInstance();

	//�ʱ�ȭ
	app->Init(L"Knights", 1250, 720, false);
	Director::GetInstance()->SetScene(SampleScene::Create());
	//����
	app->GameLoop();
	//����
	app->Release();
}

//���� �� ������ �Ű澲��.