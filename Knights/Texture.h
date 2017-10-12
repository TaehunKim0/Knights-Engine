#pragma once
class Texture
{
private:
	LPDIRECT3DTEXTURE9 m_D3DTexture;
	Vector2 m_Size;

	std::wstring m_FileName;

public:
	Texture();
	~Texture();

public:
	static Texture* Create(const std::wstring& filename); //wstring�� �����ڵ�
	bool InitFromFile(const std::wstring& filename);

};