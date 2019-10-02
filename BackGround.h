#pragma once
#include "Sprite.h"
class BackGround : public Sprite
{
public:
	BackGround();
	void Update() override;

};

class BackGroundMNG : public Singleton<BackGroundMNG>
{

};