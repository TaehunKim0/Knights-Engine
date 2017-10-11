#include "PCH.h"
#include "Renderer.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

bool Renderer::Init(HWND hWnd, int width, int height, bool fullScreen)
{
	//1. D3D ����
	if ((m_D3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	//2. Parameters ����
	D3DPRESENT_PARAMETERS pp = {};
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.BackBufferHeight = width;
	pp.BackBufferHeight = height;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = !fullScreen;
	pp.hDeviceWindow = hWnd;

	//3. Device ����
	HRESULT hr = m_D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_Device);

	//�˻�
	if FAILED(hr)
		return false;

	//4. Sprite ����
	if FAILED(D3DXCreateSprite(m_Device, &m_Sprite))
		return false;

	//Antialiasing ����
	m_Device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE); 
	m_Device->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, TRUE);

	return true;
}

bool Renderer::Release()
{
	return true;
}

void Renderer::Begin()
{
	//ȭ�鿡 �׸� �غ�.
	m_Device->BeginScene();
	//ȭ���� ������ �÷��� �ʱ�ȭ
	m_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(128, 128, 0), 1.0f, 0);
}

void Renderer::End()
{
	//�׸� �غ� ��ħ
	m_Device->EndScene();
	//ȭ�鿡 �׷���.
	m_Device->Present(NULL, NULL, NULL, NULL);
}
