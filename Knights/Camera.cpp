#include "PCH.h"
#include "Camera.h"


Camera::Camera()
	: m_Scene(nullptr)
	, m_TargetPosition(0.f, 0.f)
	, m_TargetScale(1.f, 1.f)
	, m_TargetRotation(0.f)
{
}

Camera::~Camera()
{
}

Camera * Camera::Create(Scene * scene)
{
	auto camera = new (std::nothrow) Camera();
	if (camera && camera->InitWithScene(scene))
	{
		return camera;
	}

	SAFE_DELETE(camera);
	return nullptr;
}

bool Camera::InitWithScene(Scene * scene)
{
	m_Scene = scene;

	return true;
}

void Camera::Translate(float x, float y)
{
	m_TargetPosition += Vector2(-x, -y);
}

void Camera::Scale(float x, float y)
{
	m_TargetScale += Vector2(-x, -y);
}

void Camera::Rotate(float r)
{
	m_TargetRotation += -r;
}

void Camera::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	
	//Target정보를 수정하면 m_Scene의 정보도 바뀌게 함.

	Vector2 position = m_Scene->GetPosition();
	D3DXVec2Lerp(&position, &position, &m_TargetPosition, 0.2f);
	m_Scene->SetPosition(position);

	Vector2 scale = m_Scene->GetScale();
	D3DXVec2Lerp(&scale, &scale, &m_TargetScale, 0.2f);
	m_Scene->SetScale(scale);

	Vector2 rotation = Vector2(m_Scene->GetRotation(), 0.f);
	D3DXVec2Lerp(&rotation, &rotation, &D3DXVECTOR2(m_TargetRotation, 0.f), 0.2f);
	m_Scene->SetRotation(rotation.x);

}

void Camera::Render()
{
	GameObject::Render();
}
