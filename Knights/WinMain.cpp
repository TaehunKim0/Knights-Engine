#include"PCH.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	//Apllication
	Application::GetInstance()->Init(L"Knights", 1250, 720, false);
	//����
	Application::GetInstance()->GameLoop();
	//����
}

//���� �� ������ �Ű澲��.