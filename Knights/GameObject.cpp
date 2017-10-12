#include "PCH.h"
#include "GameObject.h"


GameObject::GameObject()
	:m_Parent(nullptr)
	,m_Position(0.f,0.f)
	,m_Scale(1.f,1.f)
	,m_Size(0.f,0.f)
	,m_Rotation(0.f)
	,m_Name("")
	,m_Visible(1)
{
	D3DXMatrixIdentity(&m_Matrix); //단위행렬로 만듬
}

GameObject::~GameObject()
{
	for each(auto child in m_Children)
	{
		SAFE_DELETE(child);
	}

	m_Children.clear();

}

void GameObject::Update(float deltaTime)
{
	if (!m_Visible)
		return;

	//Children Update
	for each(const auto& child in m_Children)
	{
		child->Update(deltaTime);
	}

}

void GameObject::Render()
{
	if (!m_Visible)
		return;

	D3DXMatrixTransformation2D(&m_Matrix, NULL, 0.f, &m_Scale, NULL, m_Rotation, &m_Position);
	//Matrix 계산

	if (m_Parent)
		m_Matrix *= m_Parent->m_Matrix;

	//Children Render
	for each(const auto& child in m_Children) //const & (읽기 전용으로 가져올때 쓰자)
	{
		child->Render();
	}
}

void GameObject::SetParent(GameObject * parent)
{
	if (parent == nullptr)
		return;

	m_Parent = parent;
}

void GameObject::AddChild(GameObject * child)
{
	if (child == nullptr)
		return;

	child->m_Parent = this;

	m_Children.push_back(child);

}

void GameObject::RemoveChild(GameObject * child)
{
	if (m_Children.empty())
		return;

	if (child == nullptr)
		return;

	auto iterator = std::find(std::begin(m_Children), std::end(m_Children), child);
	if (iterator != m_Children.end())
	{
		SAFE_DELETE(child); //해제

		m_Children.erase(iterator); //m_Children 의 목록에서도 제거
	}

}

void GameObject::SetPosition(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
}
