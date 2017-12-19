#include "PCH.h"
#include "Sprite.h"


Sprite::Sprite()
	:m_Texture(nullptr)
{
}


Sprite::~Sprite()
{
}

Sprite * Sprite::Create(std::wstring filename)
{
	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->InitFromFile(filename))
	{
		return sprite;
	}

	SAFE_DELETE(sprite);
	return nullptr;
}

bool Sprite::InitFromFile(const std::wstring & filename)
{
	m_Texture = ResourcesMgr::GetInstance()->LoadTextureFromFile(filename);
	if (!m_Texture)
		return false;

	//스프라이트 사이즈 설정(텍스쳐의 사이즈와 동일)
	m_Size = m_Texture->GetSize();

	printf("m_Size : %f , %f\n", m_Size.x, m_Size.y);

	//텍스쳐를 그릴 중심 위치 설정
	SetAnchorPoint(0.5f, 0.5f);

	return true;
}

void Sprite::Update(float deltaTime)
{
	//
}

void Sprite::Render()
{
	if (!m_Visible)
		return;

	GameObject::Render();

	//그릴 영역
	RECT rect;
	SetRect(&rect, 0, 0, static_cast<int>(m_Size.x), static_cast<int>(m_Size.y));

	//그릴 중심점
	//Vector3 center(m_AnchorPoint.x, m_AnchorPoint.y, 0.f);

	//스프라이트 객체
	auto sprite = Renderer::GetInstance()->m_Sprite;

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->SetTransform(&m_Matrix);

	sprite->Draw
	(m_Texture->GetD3DTexture(),
		&rect,
		&Vector3(0.f,0.f,0.f),
		NULL,
		D3DCOLOR_XRGB(255, 255, 255)
	);

	sprite->End();
}

void Sprite::SetAnchorPoint(float x, float y)
{
	m_AnchorPoint = { x,y };

	m_AnchorPoint.x = m_Size.x * m_AnchorPoint.x;
	m_AnchorPoint.y = m_Size.y * m_AnchorPoint.y;
}
