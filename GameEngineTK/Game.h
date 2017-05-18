//
// Game.h
//

#pragma once

#include "DebugCamera.h"
#include "StepTimer.h"
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Keyboard.h>
#include "FollowCamera.h"




// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;


	/* 宣言 */

	// プリミティブバッチ
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_primitiveBatch;

	// エフェクト
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;

	// レイヤー
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;


	std::unique_ptr<DirectX::CommonStates> m_states;

	std::unique_ptr<DirectX::BasicEffect> m_effect;

	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_batch;


	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;


	float m_backBufferWidth, m_backBufferHeight;

	std::unique_ptr<DebugCamera> m_camera;
	
	// エフェクトファクトリー
	std::unique_ptr<DirectX::EffectFactory> m_factory;

	std::unique_ptr<DirectX::EffectFactory> m_ballfactory;

	std::unique_ptr<DirectX::EffectFactory> m_ballfac;

	std::unique_ptr<DirectX::EffectFactory> m_Teapotfac;

	std::unique_ptr<DirectX::EffectFactory> m_objectfactory;

	std::unique_ptr<DirectX::EffectFactory> m_robofactory;

	// モデル
	std::unique_ptr<DirectX::Model> m_model;

	std::unique_ptr<DirectX::Model> m_ballmodel;

	std::unique_ptr<DirectX::Model> m_ball;

	std::unique_ptr<DirectX::Model> m_Teapod;

	std::unique_ptr<DirectX::Model> m_object;

	std::unique_ptr<DirectX::Model> m_robo;

	// 球のワールド行列
	DirectX::SimpleMath::Matrix m_worldBall[20];

	// 角度
	float m_AngleBall;

	float m_num[20];

	float m_n[20];

	// キーボード
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	float tank_y;

	// 自機の回転角
	float tank_angle;

	// 自機の座標側の移動
	DirectX::SimpleMath::Vector3 tank_pos;

	// 自機のワールド行列
	DirectX::SimpleMath::Matrix tank_world;

	std::unique_ptr<FollowCamera> m_Camera;


};