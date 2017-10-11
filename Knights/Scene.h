#pragma once
class Scene : public GameObject
{
private:


public:
	Scene();
	~Scene();

	void Update(float deltaTime);
	void Render();
};

