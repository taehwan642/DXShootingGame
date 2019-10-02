#pragma once
#include "Sprite.h"
#include "Enemy.h"
#include "Health.h"
class Hero :
	public Sprite
{
public:
	void Update() override;
	Hero();
};

class HeroMNG : public Singleton<HeroMNG>
{
public:
	void HeroCreate();
	void HeroMovement();
	void DeleteHero();
	Hero* hero;
 };