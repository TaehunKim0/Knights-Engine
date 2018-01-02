#include "PCH.h"
#include "Input.h"


Input::Input()
{
	ZeroMemory(m_PrevKeyState, sizeof(m_PrevKeyState));
	ZeroMemory(m_NowKeyState, sizeof(m_NowKeyState));
}

Input::~Input()
{
}

void Input::Update()
{
	UpdateKeyState();
	UpdateMouseState();
}

KeyState Input::GetKeyState(int key)
{
	prevState = m_PrevKeyState[key];
	nowState = m_NowKeyState[key];

	if (prevState == false && nowState == true)
	{
		return KeyState::Down;
	}

	else if (prevState == true && nowState == true)
	{
		return KeyState::Pressed;
	}

	else if (prevState == true && nowState == false)
	{
		return KeyState::Up;
	}

	return KeyState::None;
}

KeyState Input::GetMouseState(int button)
{
	return GetKeyState(button);
}

void Input::UpdateKeyState()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevKeyState[i] = m_NowKeyState[i];
		m_NowKeyState[i] = static_cast<bool>(::GetKeyState(i) & 0x8000);
	}
}

void Input::UpdateMouseState()
{
	POINT point;
	GetCursorPos(&point); // 마우스 위치 가져옴

	//윈도우 창 위치로 변환
	ScreenToClient(Application::GetInstance()->GetHandle(), &point);

	m_MousePosition = { static_cast<float>(point.x),static_cast<float>(point.y) };

}
