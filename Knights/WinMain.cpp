#include"PCH.h"
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Application* app = Application::GetInstance();

	//�ʱ�ȭ
	app->Init(L"Knights", 1250, 720, false);
	//����
	app->GameLoop();
	//����
	app->Release();
}

//���� �� ������ �Ű澲��.