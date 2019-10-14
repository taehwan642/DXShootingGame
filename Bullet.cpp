#include "DXUT.h"
#include "Bullet.h"

void Bullet::Update()
{
	if (!_visible)
		return;
	if (bIshit)
	{
		if (Animation(L"", 3, 0.1f, 1))
		{
			_visible = false;
			bIshit = false;

		}
	}
	else
	{
		_position.y -= 10.0f;
		timer -= Time::deltaTime;
		if (timer < 0)
		{
			_visible = false;
			timer = 5.0f;
		}
		for (auto it : EnemyMNG::GetInstance()->enems)
		{
			if (it->_visible)
			{
				RECT renemy;
				if (IntersectRect(&renemy, &GetRect(), &it->GetRect()))
				{
					it->_visible = false;
					bIshit = true;
					for (auto him : ItemMNG::GetInstance()->heals)
					{
						if (!him->_visible)
						{
							if (fItem == 1)
							{
								him->_visible = true;
								him->_position = it->_position;
								break;
							}
						}
					}
				}
			}
		}
	}


}

Bullet::Bullet()
{
	Create(L"SPIT.png");
	_scale.y = 0.5f;
	_scale.x = 0.3f;
	_visible = false;
	timer = 5;
	bIshit = false;
	fItem = 0;
}

void BulletMNG::Create()
{
	for (int i = 0; i < 30; i++)
	{
		Bullet* b = new Bullet();
		bulls.push_back(b);
	}
}

void BulletMNG::ShotBullet()
{
	for (auto it : bulls)
	{
		if (!it->_visible)
		{
			it->_visible = true;
			it->Timer = 5;
			it->Create(L"SPIT.png");
			it->fItem = rand() % 10;
			//Hero의 Position을 받아와야 함;
			it->_position = HeroMNG::GetInstance()->hero->_position;
			break;
		}
	}
}
