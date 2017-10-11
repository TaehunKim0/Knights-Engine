#include"PCH.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	//Apllication
	Application::GetInstance()->Init(L"Knights", 1250, 720, false);
	//루프
	Application::GetInstance()->GameLoop();
	//해제
}

//생성 후 릴리즈 신경쓰자.