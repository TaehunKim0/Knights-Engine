#pragma once
class Sprite : public GameObject
{
private:
	Texture* m_Texture;

public:
	Sprite();
	~Sprite();

	static Sprite* Create(std::wstring filename);

	bool InitFromFile(const std::wstring& filename);

	void Update(float deltaTime);
	void Render();

	void SetAnchorPoint(float x, float y);

};

