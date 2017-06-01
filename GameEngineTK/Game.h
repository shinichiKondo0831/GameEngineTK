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
#include "Obj3d.h"

enum PLAYER_PARTS {
	PLAYER_PARTS_HEAD,
	PLAYER_PARTS_BODY,
	PLAYER_PARTS_SHOLDERL,
	PLAYER_PARTS_SHOLDERR,
	PLAYER_PARTS_LARM,
	PLAYER_PARTS_RARM,
	PLAYER_PARTS_WAITER,
	PLAYER_PARTS_FOOTL,
	PLAYER_PARTS_FOOTR,
	PLAYER_PARTS_LEGL,
	PLAYER_PARTS_LEGR,

	PLAYER_PARTS_NUM
};


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
	static const int PLAYER_ALL_PARTS = 5;

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


	/* �錾 */

	// �v���~�e�B�u�o�b�`
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_primitiveBatch;

	// �G�t�F�N�g
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;

	// ���C���[
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;


	std::unique_ptr<DirectX::CommonStates> m_states;

	std::unique_ptr<DirectX::BasicEffect> m_effect;

	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_batch;


	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;


	float m_backBufferWidth, m_backBufferHeight;

	//std::unique_ptr<DebugCamera> m_camera;
	
	// �G�t�F�N�g�t�@�N�g���[
	//std::unique_ptr<DirectX::EffectFactory> m_factory;

	std::unique_ptr<DirectX::EffectFactory> m_ballfactory;

	std::unique_ptr<DirectX::EffectFactory> m_ballfac;

	std::unique_ptr<DirectX::EffectFactory> m_Teapotfac;

	std::unique_ptr<DirectX::EffectFactory> m_objectfactory;

	std::unique_ptr<DirectX::EffectFactory> m_robofactory;

	// ���f��
	std::unique_ptr<DirectX::Model> m_model;

	std::unique_ptr<DirectX::Model> m_ballmodel;

	std::unique_ptr<DirectX::Model> m_ball;

	std::unique_ptr<DirectX::Model> m_Teapod;

	std::unique_ptr<DirectX::Model> m_object;

	std::unique_ptr<DirectX::Model> m_robo;

	/*Obj3d m_objSkydome;*/

	// �f�o�b�O�J����
	std::unique_ptr<DebugCamera> m_debugCamera;
	// �G�t�F�N�g�t�@�N�g��
	std::unique_ptr<DirectX::EffectFactory> m_factory;
	// ���f��
	Obj3d m_objSkydome;
	std::unique_ptr<DirectX::Model> m_modelGround;
	std::unique_ptr<DirectX::Model> m_modelBall;


	// ���@�I�u�W�F�N�g
	std::vector<Obj3d> m_objPlayer;

	// ���̃��[���h�s��
	DirectX::SimpleMath::Matrix m_worldBall[20];

	// �p�x
	float m_AngleBall;

	// ���@�̉�]�p
	float tank_angle;

	float angle;

	// ���@�̃M�~�b�N�Ɏg���p�x
	float m_sinAngle;

	float m_num[20];

	float m_n[20];

	// �L�[�{�[�h
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	// ���@�̍��W���̈ړ�
	DirectX::SimpleMath::Vector3 tank_pos;
	DirectX::SimpleMath::Vector3 pos;
	// ���@�̃��[���h�s��
	DirectX::SimpleMath::Matrix tank_world;

	// ���@�̃��[���h�s��
	DirectX::SimpleMath::Matrix tank_world2;

	// �J����
	std::unique_ptr<FollowCamera> m_Camera;

	float sinAngle;

	float gravity ;

	float jump;

	static float c;


};