#pragma once
class Director : public Singleton<Director>
{
private:
	//Current Scene

public:
	Director();
	~Director();

	//void SetScene()

	void Update(float deltaTime);
	void Render();


};

