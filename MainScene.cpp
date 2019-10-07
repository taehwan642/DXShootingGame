#include "DXUT.h"
#include "MainScene.h"
#include "Director.h"

void MainScene::Init()
{
	//More Later to Initalize, Goes More Back(Layer)
	BackGroundMNG::GetInstance()->BackGroundCreate();
	ItemMNG::GetInstance()->CreateHealItem();
	BulletMNG::GetInstance()->Create();
	EnemyMNG::GetInstance()->Create();
	HeroMNG::GetInstance()->HeroCreate();
	HealthMNG::GetInstance()->HealthCountDown();
	monsterspawntimer = 3;
}	

void MainScene::Update()
{
	monsterspawntimer += Time::deltaTime;
	if (DXUTWasKeyPressed(' '))
	{
		BulletMNG::GetInstance()->ShotBullet();
	}

	if (monsterspawntimer > 0.5f) 
	{
		EnemyMNG::GetInstance()->ShotBullet();
		monsterspawntimer = 0;
	}

	/*if (HealthMNG::GetInstance()->nHealth <= 0)
		Director::GetInstance()->ChangeScene(new EndScene); */

	//item Heals you
	if (DXUTWasKeyPressed('U'))
		HealthMNG::GetInstance()->HealthUp();

}

void MainScene::OnExit()
{
	delete HeroMNG::GetInstance()->hero;
	for (auto it : HealthMNG::GetInstance()->vechealt)
	{
		delete it;
	}
	HealthMNG::GetInstance()->vechealt.clear();
	for (auto it : EnemyMNG::GetInstance()->enems)
	{
		delete it;
	}
	EnemyMNG::GetInstance()->enems.clear();
	for (auto it : BulletMNG::GetInstance()->bulls)
	{
		delete it;
	}
	BulletMNG::GetInstance()->bulls.clear();
}
