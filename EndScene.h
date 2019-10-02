#pragma once
#include "Scene.h"
#include "Director.h"
#include "Scene.h"
#include "Font.h"
#include "Sprite.h"
#include "Director.h"
#include "Bullet.h"
#include "Hero.h"
#include "Enemy.h"
#include "NewDude.h"
#include "NewBullet.h"
#include "Health.h"
#include "MainScene.h"
class EndScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;
	NewBullet* newb = new NewBullet();
	float six = 600.0f;

	float dudeSpawner;
};

