#pragma once
#include "Obj3d.h"
#include <Keyboard.h>
class Player : public Obj3d
{
private:
	// キーボード
	std::unique_ptr<DirectX::Keyboard> m_keyboard;



public:
	Player();

	void Move();	// ゆくゆくはシングルトンに

	void Jump();	// ゆくゆくはシングルトンに



};