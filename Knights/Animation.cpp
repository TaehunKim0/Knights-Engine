#include "PCH.h"
#include "Animation.h"


Animation::Animation()
	:m_CurrentFrame(0)
	,m_Delay(0)
	,m_FrameCounter(0)
{
}

Animation::~Animation()
{
}

Animation * Animation::Create(int delay)
{
	auto anim = new (std::nothrow) Animation();
	if (anim && anim->Init(delay))
	{
		return anim;
	}

	SAFE_DELETE(anim);
	return nullptr;
}

bool Animation::Init(int delay)
{
	m_Delay = delay;
	return true;
}

void Animation::AddFrame(std::wstring filename)
{
	auto sprite = Sprite::Create(filename);
	sprite->SetParent(this);
	Anim.push_back(sprite);
}

void Animation::Update(float deltaTime)
{
	m_FrameCounter++;
	if (m_FrameCounter >= m_Delay) {
		m_FrameCounter = 0;
		m_CurrentFrame++;
	}

	if (m_CurrentFrame > (Anim.size() - 1))
		m_CurrentFrame = 0;

	Anim.at(m_CurrentFrame)->Update(deltaTime);

}

void Animation::Render()
{
	Anim.at(m_CurrentFrame)->Render();
}
