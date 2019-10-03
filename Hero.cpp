#include "DXUT.h"
#include "Hero.h"

void Hero::Update()
{	
	if (DXUTIsKeyDown('W') && _position.y > 45.5f)
	{
		_position.y -= 6.5f;
	}
	if (DXUTIsKeyDown('A') && _position.x > 45.5f)
	{
		_position.x -= 6.5f;
	}
	if (DXUTIsKeyDown('S') && _position.y < 670.0f)
	{
		_position.y += 6.5f;
	}
	if (DXUTIsKeyDown('D') && _position.x < 1230.0f)
	{
		_position.x += 6.5f;
	}
	cout << fUntuchableTime << endl;
	//Need To make ONTOUCHABLE time;
	for (auto it : EnemyMNG::GetInstance()->enems)
	{
		if (it->_visible == true)
		{
			RECT renemy;

			if (IntersectRect(&renemy, &GetRect(), &it->GetRect()) && !bAreyouHurt)
			{
				it->bIshit = true;
				HealthMNG::GetInstance()->HealthMinus();
				bAreyouHurt = true;
			}
		}
	}
	if (bAreyouHurt)
	{
		_color = { 0.5f,0.5f,0.5f,1 };
		fUntuchableTime += Time::deltaTime;
	}
	else
	{
		_color = { 1,1,1,1 };
	}

	if (fUntuchableTime > 1.5f)
	{
		bAreyouHurt = false;
		fUntuchableTime = 0;
	}
	//cout << "X : "<< _position.x << " Y : " << _position.y << endl;
}

Hero::Hero()
{
	Create(L"PLANE.png");
	_scale.x = 0.3f;
	_scale.y = 0.3f;
	_position.y = 500;
	_position.x = 500;
	fUntuchableTime = 0;
	_visible = true;
	bAreyouHurt = false;
}
void HeroMNG::HeroCreate()
{
	hero = new Hero();
}

void HeroMNG::HeroMovement()
{
}

void HeroMNG::DeleteHero()
{
	delete hero;
	
}


