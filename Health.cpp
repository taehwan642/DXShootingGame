#include "DXUT.h"
#include "Health.h"
//psudocode : HP needs a room to stay. and that room is only for 1 HP sprite. so that means, If There's 5 HP sprites, Those 5 Sprites needs to be seperated.

Health::Health()
{
	Create(L"PLANE.png");
	_visible = false;		
	//_position.x = 100.0f;
	//_position.y = 100.0f;
	_scale.x = 0.1f;
	_scale.y = 0.1f;
}

void Health::HealthChanger()
{
	 
}

void HealthMNG::HealthCountDown()
{
	nHealth = 5;
	for (int i = 0; i < nHealth; i++)
	{
		Health* health = new Health();
		vechealt.push_back(health);
	}
	for (int i = 0; i < vechealt.size(); i++)
	{
		//코드 줄이기 구상 ... 일단 i번째부터 시작하면, 일단 x의 포지션은 += 50이 된다.
		vechealt[i]->_position.y = 100.0f;
		vechealt[i]->_visible = true;
		vechealt[i]->_position.x = 100 + (50 * i);
	
		cout << "SIBA" << endl;
	}
}

void HealthMNG::HealthMinus()
{
	for (int i = 0; i < vechealt.size(); i++)
	{
		if (vechealt[i]->_visible)
		{
			nHealth--;
			vechealt[i]->_visible = false;
			break;
		}
	}
}
