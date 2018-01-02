#pragma once

enum class KeyState
{
	None = 0,
	Down,
	Pressed,
	Up
};

enum MouseButton
{
	Left = VK_LBUTTON,
	Right = VK_RBUTTON
};

class Input : public Singleton<Input>
{
private:
	bool m_PrevKeyState[256];
	bool m_NowKeyState[256];

	bool prevState;
	bool nowState;

	Vector2 m_MousePosition;

public:
	Input();
	~Input();

	void Update();

	KeyState GetKeyState(int key);
	KeyState GetMouseState(int button);

	Vector2 GetMousePosition()
	{
		return m_MousePosition;
	}

	bool GetIsInput(int key)
	{
		prevState = m_PrevKeyState[key];
		nowState = m_NowKeyState[key];

		if (nowState == true)
			return true;

		else
			return false;

	}

	void UpdateKeyState();
	void UpdateMouseState();
};

