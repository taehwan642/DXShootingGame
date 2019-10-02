#pragma once
#include "Sprite.h"
#include "Hero.h"
#include "Enemy.h"
class Bullet :
	public Sprite
{
public:
	void Update() override;
	Bullet();
	float timer;
	bool bIshit;
};

class BulletMNG : public Singleton<BulletMNG>
{
public:

	void Create();
	void ShotBullet();
	vector<Bullet*> bulls;
	//void DeleteBullet();
};