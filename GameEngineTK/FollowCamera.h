/// <summary>
/// ���@�ɒǏ]����J�����N���X
/// </summary>
#pragma once

#include "Camera.h"
#include <Keyboard.h>

class FollowCamera : public Camera
{
public:
	// �J�����Ǝ��@�̋���
	static const float CAMERA_DISTANCE;
	// �R���X�g���N�^
	FollowCamera(int width, int height);
	// ���t���[���X�V
	void Update() override;

	// TPS�J�����̏�����
	void InitializeTPS();

	// �Ǐ]�Ώۍ��W���Z�b�g
	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	// �Ǐ]�Ώۊp�x���Z�b�g
	void SetTargetAngle(float targetAngle);

	// �L�[�{�[�h���Z�b�g
	void SetKeyboard(DirectX::Keyboard* keyboard);

protected:
	// �Ǐ]�Ώۂ̍��W
	DirectX::SimpleMath::Vector3 m_targetPos;
	// �Ǐ]�Ώۂ̊p�x
	float m_targetAngle;
	// �L�[�{�[�h
	DirectX::Keyboard* m_keyboard;
	// �L�[�{�[�h�g���b�J�[
	DirectX::Keyboard::KeyboardStateTracker m_keyboardTracker;
	// FPS�J�����t���O
	bool isFPS;
};
