#pragma once
class Sprite;
class Animation : public GameObject
{
private:
	std::vector<Sprite*> Anim;

	int m_CurrentFrame;
	int m_Delay;
	int m_FrameCounter;

public:
	Animation();
	~Animation();

	static Animation* Create(int delay);

	bool Init(int delay);

	void AddFrame(std::wstring filename);

public:
	void Update(float deltaTime);
	void Render();
};

