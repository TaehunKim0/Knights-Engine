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
	//1. D3D 생성
	if ((m_D3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	//2. Parameters 설정
	D3DPRESENT_PARAMETERS pp = {};
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.BackBufferHeight = width;
	pp.BackBufferHeight = height;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = !fullScreen;
	pp.hDeviceWindow = hWnd;

	//3. Device 생성
	HRESULT hr = m_D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_Device);

	//검사
	if FAILED(hr)
		return false;

	//4. Sprite 생성
	if FAILED(D3DXCreateSprite(m_Device, &m_Sprite))
		return false;

	//Antialiasing 설정
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
	//화면에 그릴 준비.
	m_Device->BeginScene();
	//화면을 설정한 컬러로 초기화
	m_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(128, 128, 0), 1.0f, 0);
}

void Renderer::End()
{
	//그릴 준비를 마침
	m_Device->EndScene();
	//화면에 그려줌.
	m_Device->Present(NULL, NULL, NULL, NULL);
}
