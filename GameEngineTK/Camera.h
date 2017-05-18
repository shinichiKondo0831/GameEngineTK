#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

class Camera
{
public:
	// メンバ関数
	Camera(int width,int Height);
	virtual ~Camera();

	// 更新
	virtual void Update();

	// View座標を取得
	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	// 射影行列を取得
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	// 視点座標をセット
	void SetEyePos(DirectX::SimpleMath::Vector3 eyepos);

	// 視点座標をセット
	void SetRefPos(DirectX::SimpleMath::Vector3 refpos);

	// 視点座標をセット
	void SetUpPos(DirectX::SimpleMath::Vector3 uppos);

	// 垂直方向視野角のセット
	const void SetFovY(float& fovY);

	// アスペクト比のセット
	const void SetAspect(float& aspect);

	// ニアクリップのセット
	const void SetNearclip(float& nearclip);

	// ファークリップのセット
	const void SetFarclip(float& farclip);

protected:
	// メンバ変数
	
	// ビュー行列
	DirectX::SimpleMath::Matrix m_view;
	// 射影行列
	DirectX::SimpleMath::Matrix m_proj;
	// カメラの位置
	DirectX::SimpleMath::Vector3 m_eyepos;
	// どこをみているのか
	DirectX::SimpleMath::Vector3 m_refpos;
	// 上方向ベクトル
	DirectX::SimpleMath::Vector3 m_upvec;
	// 垂直方向視野角
	float m_fovY;
	// 画面横幅と立幅の比率
	float m_aspect;
	// 手前の表示限界距離
	float m_nearclip;
	// 奥の表示限界距離
	float m_farclip;
	// 
};
