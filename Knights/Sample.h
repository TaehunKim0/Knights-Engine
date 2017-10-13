#pragma once
class Sample : public Scene
{
private:
	Sprite* man;

public:
	CREATE_FUNC(Sample);

	Sample();
	~Sample();

	bool Init();
	void Update(float deltaTime);
	void Render();

};

