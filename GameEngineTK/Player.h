#pragma once
#include "Obj3d.h"
#include <Keyboard.h>
class Player : public Obj3d
{
private:
	// �L�[�{�[�h
	std::unique_ptr<DirectX::Keyboard> m_keyboard;



public:
	Player();

	void Move();	// �䂭�䂭�̓V���O���g����

	void Jump();	// �䂭�䂭�̓V���O���g����



};