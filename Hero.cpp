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
	
	for (auto it : EnemyMNG::GetInstance()->enems)
	{
		if (it->_visible == true)
		{
			RECT renemy;

			if (IntersectRect(&renemy, &GetRect(), &it->GetRect()))
			{
				it->_visible = false;
				HealthMNG::GetInstance()->HealthMinus();
			}
		}
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
	_visible = true;
}
void HeroMNG::HeroCreate()
{
	hero = new Hero();
	cout << "비션갱 스컬ㄹㄹ";
}

void HeroMNG::HeroMovement()
{
}

void HeroMNG::DeleteHero()
{
	delete hero;
	
}


