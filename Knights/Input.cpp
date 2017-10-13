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
}

KeyState Input::GetKeyState(int key)
{
	bool prevState = m_PrevKeyState[key];
	bool nowState = m_NowKeyState[key];

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

void Input::UpdateKeyState()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevKeyState[i] = m_NowKeyState[i];
		m_NowKeyState[i] = static_cast<bool>(::GetKeyState(i) & 0x8000);
	}
}