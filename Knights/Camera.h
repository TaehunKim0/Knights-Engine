#pragma once
class Camera : public GameObject
{
private:
	Scene* m_Scene;

	Vector2 m_TargetPosition;
	Vector2 m_TargetScale;
	float m_TargetRotation;

public:
	Camera();
	~Camera();

	static Camera* Create(Scene* scene);

	bool InitWithScene(Scene* scene);

	void Translate(float x, float y);
	void Scale(float x, float y);
	void Rotate(float r);

	void Update(float deltaTime);
	void Render();
};

