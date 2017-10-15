#include"PCH.h"
#include "Application.h"

Application::Application()
	: m_handle(nullptr)
	, ScreenHeight(0)
	, ScreenWidth(0)
{
}

Application::~Application()
{
}

bool Application::Init(wchar_t* title, int width, int height, bool fullScreen)
{
	Title = title;
	ScreenWidth = width;
	ScreenHeight = height;

	//윈도우 초기화
	if (!(_CreateWindow(ScreenWidth, ScreenHeight, fullScreen)))
		return false;

	//렌더러 초기화
	if (!(_CreateRenderer(fullScreen)))
		return false;

	return true;
}

bool Application::Release()
{
	return true;
}

bool Application::GameLoop()
{
	ShowWindow(m_handle, SW_SHOWDEFAULT);

	MSG Msg;
	ZeroMemory(&Msg, sizeof(Msg));

	while (Msg.message != WM_QUIT)
	{
		if (PeekMessage(&Msg, m_handle, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}

		else
		{
			Input::GetInstance()->Update();
			
			Director::GetInstance()->Update(16.f);
			Renderer::GetInstance()->Begin();
			Director::GetInstance()->Render();
			Renderer::GetInstance()->End();
		}
	}

	return true;
}
LRESULT Application::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);

	default:
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

bool Application::_CreateWindow(int width, int height, bool fullScreen)
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = Title;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (RegisterClass(&wc) == NULL)
		return false;

	DWORD Style = WS_OVERLAPPEDWINDOW;
	int x = 0, y = 0;

	if(fullScreen) //전체화면
	{
		Style = WS_POPUP | WS_EX_TOPMOST;
	}
	else //창 화면
	{
		Style = WS_POPUP;

		RECT rect;
		SetRect(&rect, 0, 0, ScreenWidth, ScreenHeight);

		AdjustWindowRect(&rect, Style, false);

		width = (rect.right - rect.left);
		height = (rect.bottom - rect.top);

		x = y = CW_USEDEFAULT;
	}
	
	m_handle = CreateWindow(L"Ennead", Title, Style, x, y, width, height, NULL, NULL, wc.hInstance, NULL);
	
	if (m_handle == NULL)
		return false;

	

	return true;
}

bool Application::_CreateRenderer(bool fullScreen)
{
	Renderer::GetInstance()->Init(m_handle, ScreenWidth, ScreenHeight, fullScreen);

	return true;
}