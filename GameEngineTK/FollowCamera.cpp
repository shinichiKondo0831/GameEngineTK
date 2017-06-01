#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

// �ÓI�����o�ϐ��̏�����
const float FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int width, int height)
	: Camera(width, height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.0f;
	m_keyboard = nullptr;
	isFPS = false;
	InitializeTPS();
}

void FollowCamera::Update()
{
	Vector3 eyepos, refpos;

	// �L�[�{�[�h�̏�Ԃ��擾
	Keyboard::State keystate = m_keyboard->GetState();
	m_keyboardTracker.Update(keystate);

	// C�L�[����������
	if (m_keyboardTracker.IsKeyPressed(Keyboard::Keyboard::C))
	{
		// �t���O��؂�ւ�
		isFPS = !isFPS;
		if (!isFPS)
		{
			InitializeTPS();
		}
	}

	if (isFPS)
	{ // FPS�J����
		Vector3 position;
		// ���@�̏��0.2���̈ʒu�ɃJ������u��
		position = m_targetPos + Vector3(0, 0.2f, 0);
		// �Q�Ɠ_���王�_�ւ̍���
		Vector3 cameraV(0, 0, -CAMERA_DISTANCE);
		// ���@�̌��ɉ�荞�ނ��߂̉�]
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		// �����x�N�g������]������
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		// ������Ɛi�񂾈ʒu�����_
		eyepos = position + cameraV * 0.1f;
		// ������i�񂾈ʒu���Q�Ɠ_
		refpos = position + cameraV;
	}
	else
	{ // TPS�J����
	  // ���@�̏���Q���̈ʒu�𑨂���
		refpos = m_targetPos + Vector3(0, 2, 0);
		// �Q�Ɠ_���王�_�ւ̍���
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);
		// ���@�̌��ɉ�荞�ނ��߂̉�]
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		// �����x�N�g������]������
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		// ���_���W���v�Z
		eyepos = refpos + cameraV;
		// ���_�����݈ʒu������
		eyepos = m_eyepos + (eyepos - m_eyepos) * 0.05f;
		// �Q�Ɠ_�����݈ʒu������
		refpos = m_refpos + (refpos - m_refpos) * 0.20f;
	}




	SetEyePos(eyepos);
	SetRefPos(refpos);

	// ���N���X�̍X�V
	Camera::Update();
}

void FollowCamera::InitializeTPS()
{
	Vector3 eyepos, refpos;

	// ���@�̏���Q���̈ʒu�𑨂���
	refpos = m_targetPos + Vector3(0, 2, 0);
	// �Q�Ɠ_���王�_�ւ̍���
	Vector3 cameraV(0, 0, CAMERA_DISTANCE);
	// ���@�̌��ɉ�荞�ނ��߂̉�]
	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
	// �����x�N�g������]������
	cameraV = Vector3::TransformNormal(cameraV, rotmat);
	// ���_���W���v�Z
	eyepos = refpos + cameraV;

	SetEyePos(eyepos);
	SetRefPos(refpos);
}

void FollowCamera::SetTargetPos(const DirectX::SimpleMath::Vector3 & targetpos)
{
	m_targetPos = targetpos;
}

void FollowCamera::SetTargetAngle(float targetAngle)
{
	m_targetAngle = targetAngle;
}

void FollowCamera::SetKeyboard(DirectX::Keyboard * keyboard)
{
	m_keyboard = keyboard;
}
