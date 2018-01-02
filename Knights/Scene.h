#pragma once
class Camera;
class Scene : public GameObject
{
private:
	Camera* m_Camera;

public:
	CREATE_FUNC(Scene);

	Scene();
	virtual ~Scene();

	virtual void Release();
	virtual bool Init();
	virtual void Update(float deltaTime);
 	virtual void Render();

public:
	Camera* GetCamera()
	{
		return m_Camera;
	}
};