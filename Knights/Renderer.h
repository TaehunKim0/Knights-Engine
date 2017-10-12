#pragma once
class Renderer : public Singleton<Renderer>
{
public:
	LPDIRECT3D9 m_D3D;
	LPDIRECT3DDEVICE9 m_Device;
	LPD3DXSPRITE m_Sprite;

public:
	Renderer();
	~Renderer();

	bool Init(HWND hWnd, int width, int height, bool fullScreen);
	bool Release();

	void Begin();
	void End();

public:
	

};

