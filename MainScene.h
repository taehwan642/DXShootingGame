#pragma once
#include "Scene.h"
#include "EndScene.h"
#include "Font.h"
#include "Sprite.h"
#include "Director.h"
#include "Bullet.h"
#include "Hero.h"
#include "Enemy.h"
#include "Health.h"

class MainScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;

	float monsterspawntimer;
};

