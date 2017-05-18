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

	// 毎フレーム更新
	void Update() override;

	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	void SetTargetAngle(const float& targetangle);

	void SetKeyboard(DirectX::Keyboard* keyboard);

protected:
	// 追従対象の座標
	DirectX::SimpleMath::Vector3 m_targetPos;

	// 追従対象の角度
	float m_targetAngle;

	// キーボード
	DirectX::Keyboard* m_keyboard;

	// キーボードトラッカー
	DirectX::Keyboard::KeyboardStateTracker m_keyboardTracker;

	bool m_flag;
};