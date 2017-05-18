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

	// �L�[�{�[�h�̏�Ԃ��擾
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
			// �t���O��؂�ւ���
			m_flag = true;
		}
	
	}
	if(m_flag == false)
	{	// FPS
		Vector3 position;
		// ���@�̏��0.2����̈ʒu���Ƃ炦��
		position = m_targetPos + Vector3(0, 0.2f, 0);

		// �Q�Ɠ_���王�_�ւ̍���
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);
		// ���@�̌��ɉ�荞�ނ��߂̉�]
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		// �����x�N�g������]������
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		eyepos = position + cameraV * 0.1;
		// �Q�Ɠ_���W���v�Z
		refpos = eyepos + cameraV;
	}

	if(m_flag)
	{
		// TPS�J����
		// ���@�̏���Q����̈ʒu���Ƃ炦��
		refpos = m_targetPos + Vector3(0, 2, 0);

		// �Q�Ɠ_���王�_�ւ̍���
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);
		// ���@�̌��ɉ�荞�ނ��߂̉�]
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		// �����x�N�g������]������
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		// ���_���W���v�Z
		eyepos = refpos + cameraV;
		//���`���
		/*eyepos = m_eyepos + (eyepos - m_eyepos) * 0.05f;

		refpos = m_refpos + (refpos - m_refpos) * -0.05f;*/
	}

	

	this->SetEyePos(eyepos);
	this->SetRefPos(refpos);
	// ���J�����̍X�V
	Camera::Update();
	
}