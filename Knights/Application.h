#pragma once
/*
 윈도우와 렌더러를 생성한다.
 게임 루프를 도는 역할
*/

class Application : public Singleton<Application>
{
private:
	HWND m_handle;
	int ScreenWidth;
	int ScreenHeight;
	wchar_t* Title;

public:
	Application();
	~Application();

public:
	bool Init(wchar_t* title, int width, int height, bool fullScreen);
	bool Release();
	bool GameLoop();

public:
	bool _CreateWindow(int width, int height, bool fullScreen);
	bool _CreateRenderer(bool fullScreen);

public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);


};

