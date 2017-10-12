#include "PCH.h"
#include "Texture.h"


Texture::Texture()
	:m_D3DTexture(nullptr)
	,m_Size(0.f,0.f)
	,m_FileName(L"")
{
}

Texture::~Texture()
{
}

Texture * Texture::Create(const std::wstring & filename)
{
	//�ؽ��ĸ� �����Ѵ�.
	auto texture = new (std::nothrow) Texture(); //std::nothrow (���ܸ� ������ �ʰ� null ��ȯ)
	if (texture && texture->InitFromFile(filename))
	{
		return texture;
	}

	SAFE_DELETE(texture);
	return nullptr;
}

bool Texture::InitFromFile(const std::wstring & filename)
{
	//1. ���Ϸκ��� �ؽ��ĸ� �����.
	HRESULT hr;
		hr = D3DXCreateTextureFromFileEx
		(
			Renderer::GetInstance()->m_Device,
			filename.c_str(),
			D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
			1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
			D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL,
			&m_D3DTexture
		);

	if FAILED(hr)
		return false;

	//2. �ؽ��� ������ �����Ѵ�.
	D3DSURFACE_DESC desc;
	m_D3DTexture->GetLevelDesc(0, &desc);

	m_Size.x = static_cast<float>(desc.Width); //uint -> float ����ȯ
	m_Size.y = static_cast<float>(desc.Height);
	
	m_FileName = filename;

	return true;
}
