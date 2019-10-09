#pragma once
#include "Sprite.h"
#include "Hero.h"
#include "Enemy.h"
#include "Item.h"
class Bullet :
	public Sprite
{
public:
	void Update() override;
	Bullet();
	float timer;
	bool bIshit;
	float fItem;
};

class BulletMNG : public Singleton<BulletMNG>
{
public:

	void Create();
	void ShotBullet();
	vector<Bullet*> bulls;
	//void DeleteBullet();
};