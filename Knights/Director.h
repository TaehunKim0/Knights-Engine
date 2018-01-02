#pragma once
class Director : public Singleton<Director>
{
private:
	Scene* CurrentScene;

public:
	Director();
	~Director();

	void SetScene(Scene* scene);

	void Update(float deltaTime);
	void Render();

	bool IsInWindowRect(Vector2 pos);

};