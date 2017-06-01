/// <summary>
/// �R�c�I�u�W�F�N�g�̃N���X
/// </summary>
#pragma once

#include <memory>
#include <windows.h>
#include <wrl/client.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>

#include "Camera.h"

class Obj3d
{
	// �ÓI�����o
public:
	// �ÓI�����o�̏�����
	static void InitializeStatic(Camera* pCamera,
		Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext);

private:
	// �J����
	static Camera* m_pCamera;
	// �f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	// �R���e�L�X�g
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
	// �ėp�X�e�[�g
	static std::unique_ptr<DirectX::CommonStates> m_states;
	// �G�t�F�N�g�t�@�N�g��
	static std::unique_ptr<DirectX::EffectFactory> m_factory;

	//static std::map<DirectX::Model, wstring> m_models;

public:
	// �R���X�g���N�^
	Obj3d();

	// ���f���̓ǂݍ���
	void LoadModel(const wchar_t* fileName);

	void Update();

	void Draw();

	// setter
	// �X�P�[�����O�p
	void SetScale(const DirectX::SimpleMath::Vector3& scale) { m_scale = scale; }
	// ��]�p�p
	void SetRotation(const DirectX::SimpleMath::Vector3& rotation) { m_rotation = rotation; }
	// ���s�ړ��p
	void SetTranslation(const DirectX::SimpleMath::Vector3& translation) { m_translation = translation; }
	// �e�s��p
	void SetObjParent(Obj3d* pObjParent) { m_pObjParent = pObjParent; }
	// getter
	// �X�P�[�����O�p
	const DirectX::SimpleMath::Vector3& GetScale() { return m_scale; }
	// ��]�p�p
	const DirectX::SimpleMath::Vector3& GetRotation() { return m_rotation; }
	// ���s�ړ��p
	const DirectX::SimpleMath::Vector3& GetTranslation() { return m_translation; }
	// ���[���h�s����擾
	const DirectX::SimpleMath::Matrix& GetWorld() { return m_world; }
	// �e�s��p
	Obj3d* GetObjParent() { return m_pObjParent; }

private:
	// ���f���̃��j�[�N�|�C���^
	std::unique_ptr<DirectX::Model> m_model;
	// �X�P�[�����O
	DirectX::SimpleMath::Vector3 m_scale;
	// ��]�p
	DirectX::SimpleMath::Vector3 m_rotation;
	// ���s�ړ�
	DirectX::SimpleMath::Vector3 m_translation;
	// ���[���h�s��
	DirectX::SimpleMath::Matrix m_world;
	// �e�ƂȂ�R�c�I�u�W�F�N�g�̃N���X�̃|�C���^
	Obj3d* m_pObjParent;
};

