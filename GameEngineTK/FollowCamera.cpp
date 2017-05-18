#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

const float FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int width, int height)
	:Camera(width,height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.0f;
	m_keyboard = nullptr;
	m_flag = false;
}


FollowCamera::~FollowCamera()
{

}

void FollowCamera::SetTargetPos(const Vector3& targetpos)
{
	m_targetPos = targetpos;
}

void FollowCamera::SetTargetAngle(const float& targetangle)
{
	m_targetAngle = targetangle;
}

void FollowCamera::SetKeyboard(DirectX::Keyboard* keyboard)
{
	m_keyboard = keyboard;
}


void FollowCamera::Update()
{
	Vector3 eyepos, refpos;

	// キーボードの状態を取得
	Keyboard::State keystate = m_keyboard->GetState();
	m_keyboardTracker.Update(keystate);

	



	if (m_keyboardTracker.IsKeyPressed(Keyboard::C))
	{
		if (m_flag)
		{
			m_flag = false;
		}
		else
		{
			// フラグを切り替える
			m_flag = true;
		}
	
	}
	if(m_flag == false)
	{	// FPS
		Vector3 position;
		// 自機の上方0.2ｍ上の位置をとらえる
		position = m_targetPos + Vector3(0, 0.2f, 0);

		// 参照点から視点への差分
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);
		// 自機の後ろに回り込むための回転
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		// 差分ベクトルを回転させる
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		eyepos = position + cameraV * 0.1;
		// 参照点座標を計算
		refpos = eyepos + cameraV;
	}

	if(m_flag)
	{
		// TPSカメラ
		// 自機の上方２ｍ上の位置をとらえる
		refpos = m_targetPos + Vector3(0, 2, 0);

		// 参照点から視点への差分
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);
		// 自機の後ろに回り込むための回転
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		// 差分ベクトルを回転させる
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		// 視点座標を計算
		eyepos = refpos + cameraV;
		//線形補間
		/*eyepos = m_eyepos + (eyepos - m_eyepos) * 0.05f;

		refpos = m_refpos + (refpos - m_refpos) * -0.05f;*/
	}

	

	this->SetEyePos(eyepos);
	this->SetRefPos(refpos);
	// 基底カメラの更新
	Camera::Update();
	
}