#pragma once
class Scene : public GameObject
{
private:
	//���� ī�޶� ����� ����

public:
	Scene();
	virtual ~Scene();

	virtual void Update(float deltaTime);
 	virtual void Render();
};