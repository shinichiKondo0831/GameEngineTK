#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

class Camera
{
public:
	// �����o�֐�
	Camera(int width,int Height);
	virtual ~Camera();

	// �X�V
	virtual void Update();

	// View���W���擾
	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	// �ˉe�s����擾
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	// ���_���W���Z�b�g
	void SetEyePos(DirectX::SimpleMath::Vector3 eyepos);

	// ���_���W���Z�b�g
	void SetRefPos(DirectX::SimpleMath::Vector3 refpos);

	// ���_���W���Z�b�g
	void SetUpPos(DirectX::SimpleMath::Vector3 uppos);

	// ������������p�̃Z�b�g
	const void SetFovY(float& fovY);

	// �A�X�y�N�g��̃Z�b�g
	const void SetAspect(float& aspect);

	// �j�A�N���b�v�̃Z�b�g
	const void SetNearclip(float& nearclip);

	// �t�@�[�N���b�v�̃Z�b�g
	const void SetFarclip(float& farclip);

protected:
	// �����o�ϐ�
	
	// �r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	// �ˉe�s��
	DirectX::SimpleMath::Matrix m_proj;
	// �J�����̈ʒu
	DirectX::SimpleMath::Vector3 m_eyepos;
	// �ǂ����݂Ă���̂�
	DirectX::SimpleMath::Vector3 m_refpos;
	// ������x�N�g��
	DirectX::SimpleMath::Vector3 m_upvec;
	// ������������p
	float m_fovY;
	// ��ʉ����Ɨ����̔䗦
	float m_aspect;
	// ��O�̕\�����E����
	float m_nearclip;
	// ���̕\�����E����
	float m_farclip;
	// 
};
