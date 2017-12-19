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

	void UpdateKeyState();
	void UpdateMouseState();
};

