#include "DXUT.h"
#include "Enemy.h"
#include <time.h>
Enemy::Enemy()
{
	time = 0;
	pos = 0;
	Create(L"ENEMY.png");
	_scale.x = 0.3f;
	_scale.y = 0.3f;
	_visible = false;
	timer = 0;
	Whatareyou = true;
}

void Enemy::Update()
{
	if (!_visible)
		return;

	timer -= Time::deltaTime;
	if (timer < 0)
	{
		_visible = false;
		timer = 5.0f;
	}
	OnlineState();
	if (Whatareyou)
	{
		Strike(5);
	}
	else
	{
		LeftRight(5);
	}
}

void Enemy::Strike(float spd)
{
	_position.y += spd;

}


void Enemy::LeftRight(float spd)
{
	time += Time::deltaTime * 10;
	pos = cos(time) * 8;
	_position.x += pos;
	_position.y += spd;
}

void EnemyMNG::Create()
{
	ranv = 0;
	for (int i = 0; i < 30; i++)
	{
		e = new Enemy();
		enems.push_back(e);
	}
}

void EnemyMNG::ShotBullet()
{
	for (auto it : enems)
	{
		if (!it->_visible)
		{
			it->_visible = true;
			it->timer = 5;
			//Hero의 Position을 받아와야 함;
			it->_position.y = 0;
			it->_position.x = ((rand() % 1151) + 50);
			ranv = rand() % 2;
			if (ranv == 0)
			{
				it->Whatareyou = true;
			}
			else
			{
				it->Whatareyou = false;
			}
			return;
		}
	}
}
void Enemy::OnlineState()
{
	if (DXUTWasKeyPressed('O')) { Whatareyou = true; cout << "false" << endl; }
	else if (DXUTWasKeyPressed('P')) { Whatareyou = false; cout << "false" << endl; }
}
