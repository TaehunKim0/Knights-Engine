#include"PCH.h"
#include"Sample.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);

#endif
	Application* app = Application::GetInstance();
	//�ʱ�ȭ
	app->Init(L"Knights", 1400, 990, false);
	Director::GetInstance()->SetScene(Sample::Create());
	//����
	app->GameLoop();
	//����
	app->Release();
}

//���� �� ������ �Ű澲��.