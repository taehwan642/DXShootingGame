#pragma once
#include "Sprite.h"
class BackGround : public Sprite
{
public:
	BackGround();
	void Update() override;
	Sprite* sp[2];
};

class BackGroundMNG : public Singleton<BackGroundMNG>
{
public:
	void BackGroundCreate();
	BackGround* bg;
};