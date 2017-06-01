//------------------------
// �J�����𐧌䂷��N���X
//------------------------
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

class Camera
{
public:
	Camera(int width, int height);

	virtual ~Camera();

	// �X�V
	virtual void Update();

	// �r���[�s����擾
	const DirectX::SimpleMath::Matrix& GetView();

	// �ˉe�s����擾
	const DirectX::SimpleMath::Matrix& GetProj();

	// ���_���W���Z�b�g
	void SetEyePos(const DirectX::SimpleMath::Vector3& eyepos);

	// �Q�Ɠ_���W���Z�b�g
	void SetRefPos(const DirectX::SimpleMath::Vector3& refpos);

	// ������x�N�g�����Z�b�g
	void SetUpVec(const DirectX::SimpleMath::Vector3& upvec);

	// ������������p���Z�b�g
	void SetFovY(float fovY);

	// �A�X�y�N�g����Z�b�g
	void SetAspect(float aspect);

	// �j�A�N���b�v���Z�b�g
	void SetNearClip(float nearclip);

	// �t�@�[�N���b�v���Z�b�g
	void SetFarClip(float farclip);

protected:
	// �r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	// �J�����̈ʒu�i���_���W�j
	DirectX::SimpleMath::Vector3 m_eyepos;
	// �ǂ��݂̂�̂��i�����_/�Q�Ɠ_)
	DirectX::SimpleMath::Vector3 m_refpos;
	// ������x�N�g��
	DirectX::SimpleMath::Vector3 m_upvec;
	// �ˉe�s��
	DirectX::SimpleMath::Matrix m_proj;
	// ������������p
	float m_fovY;
	// ��ʉ����Əc���̔䗦�i�A�X�y�N�g��j
	float m_aspect;
	// ��O�̕\�����E����
	float m_nearclip;
	// ���̕\�����E����
	float m_farclip;
};
