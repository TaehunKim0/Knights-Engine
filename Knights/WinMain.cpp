#include"PCH.h"
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Application* app = Application::GetInstance();

	//초기화
	app->Init(L"Knights", 1250, 720, false);
	//루프
	app->GameLoop();
	//해제
	app->Release();
}

//생성 후 릴리즈 신경쓰자.