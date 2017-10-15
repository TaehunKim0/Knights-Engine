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
	//초기화
	app->Init(L"Knights", 1400, 990, false);
	Director::GetInstance()->SetScene(Sample::Create());
	//루프
	app->GameLoop();
	//해제
	app->Release();
}

//생성 후 릴리즈 신경쓰자.