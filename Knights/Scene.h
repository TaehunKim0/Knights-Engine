#pragma once
class Scene : public GameObject
{
private:
	//씬의 카메라를 여기다 두자

public:
	Scene();
	virtual ~Scene();

	virtual void Update(float deltaTime);
 	virtual void Render();
};