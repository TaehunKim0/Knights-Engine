#pragma once

enum class KeyState
{
	None = 0,
	Down,
	Pressed,
	Up
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
	void UpdateKeyState();
};

