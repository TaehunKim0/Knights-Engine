#pragma once
class Sprite : public GameObject
{
private:
	Texture* m_Texture;
	bool m_Alpha;

public:
	Sprite();
	~Sprite();

	static Sprite* Create(std::wstring filename);

	bool InitFromFile(const std::wstring& filename);

	void Update(float deltaTime);
	void Render();

	void SetAnchorPoint(float x, float y);

	Texture* GetTexture()
	{
		return m_Texture;
	}

	void Alpha(bool a)
	{
		m_Alpha = a;
	}

};

