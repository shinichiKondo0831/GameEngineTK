#pragma once

#//include "Game.h"
#include "Camera.h"
#include <Keyboard.h>

class FollowCamera : public Camera
{
public:
	const static float CAMERA_DISTANCE;

	FollowCamera(int width,int height);

	~FollowCamera();

	// ���t���[���X�V
	void Update() override;

	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	void SetTargetAngle(const float& targetangle);

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

	bool m_flag;
};