#include "DXUT.h"
#include "EndScene.h"


void EndScene::Init()
{

	NewDudeMNG::GetInstance()->CreateNewDude();
	HeroMNG::GetInstance()->HeroCreate();
	dudeSpawner = 1.5f;
}

void EndScene::Update()
{
	dudeSpawner += Time::deltaTime;
	if (DXUTWasKeyPressed('U'))
		Director::GetInstance()->ChangeScene(new MainScene);

	if (dudeSpawner > 2)
	{
		NewDudeMNG::GetInstance()->ComeOutDude();
		dudeSpawner = 0;
	}
}

void EndScene::OnExit()
{
	HeroMNG::GetInstance()->DeleteHero();
}