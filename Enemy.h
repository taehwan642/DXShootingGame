#pragma once
#include "Sprite.h"
#include "Health.h"
#include "Mover.h"

class Enemy : public Sprite
{
public:
	Enemy();
	void Update() override;
	void Strike(float spd);
	void LeftRight(float spd);
	float time;
	float pos;
	float timer;
	bool Whatareyou;
	void OnlineState();
	bool bIshit;
};

class EnemyMNG : public Singleton<EnemyMNG>
{
public:
	void Create();
	void ShotBullet();
	int ranv;
	Enemy* e;
	vector<Enemy*> enems;
};



