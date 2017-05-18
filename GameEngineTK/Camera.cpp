#include "Camera.h"
#include "Game.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
// メンバ変数の初期化
Camera::Camera(int width, int Height):m_eyepos(0, 0, 10.0f),m_refpos(0, 0, 0),
m_upvec(0, 1, 0), m_fovY(XMConvertToRadians(60.0f)),m_aspect((float)width / Height),
m_nearclip(0.1f), m_farclip(1000.0f)
{
	

	// ビュー行列の生成
	m_view = Matrix::CreateLookAt(Vector3(0.f, 2.f, 50.f),
	Vector3(10,10,10), Vector3(0,1,0));

	// 射影行列の生成
	m_proj = Matrix::CreatePerspectiveFieldOfView(XM_PI / 4.f,
	float(width) / float(Height), 0.1f, 1000.f);
}


Camera::~Camera()
{

}

// 更新
void Camera::Update()
{
	m_view = Matrix::CreateLookAt(m_eyepos,
		m_refpos, m_upvec);

	m_proj = Matrix::CreatePerspectiveFieldOfView(
		m_fovY,m_aspect,m_nearclip,m_farclip);
}


// ビュー行列を取得する
const DirectX::SimpleMath::Matrix& Camera::GetViewMatrix()
{
	return m_view;
}


// 射影行列を取得する
const DirectX::SimpleMath::Matrix& Camera::GetProjectionMatrix()
{
	return m_proj;
}

// 視点座標をセット
void Camera::SetEyePos(DirectX::SimpleMath::Vector3 eyepos)
{
	m_eyepos = eyepos;
}


// 視点座標をセット
void Camera::SetRefPos(DirectX::SimpleMath::Vector3 refpos)
{
	m_refpos = refpos;
}

// 視点座標をセット
void Camera::SetUpPos(DirectX::SimpleMath::Vector3 uppos)
{
	m_upvec = uppos;
}

const void Camera::SetFovY(float & fovY)
{
	m_fovY = fovY;
}

const void Camera::SetAspect(float & aspect)
{
	m_aspect = aspect;
}

const void Camera::SetNearclip(float & nearclip)
{
	m_nearclip = nearclip;
}

const void Camera::SetFarclip(float & farclip)
{
	m_farclip = farclip;
}
