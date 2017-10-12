#pragma once
class SampleScene : public Scene
{
public:
	Sprite* man;

	CREATE_FUNC(SampleScene);

public:
	SampleScene();
	~SampleScene();

	bool Init();
	void Update(float deltaTime);
	void Render();
};

