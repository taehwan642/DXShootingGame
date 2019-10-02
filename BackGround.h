#pragma once
#include "Sprite.h"
class BackGround : public Sprite
{
public:
	BackGround();
	void Update() override;
	Sprite* s1;
	Sprite* s2;
};

class BackGroundMNG : public Singleton<BackGroundMNG>
{
public:
	void BackGroundCreate();
	BackGround* bg;
};