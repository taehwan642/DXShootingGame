#include "DXUT.h"
#include "NewDude.h"

NewDude::NewDude()
{
	ypos = 0;
	ganggogo = 0;
	Create(L"Enemy.png");
	_scale.x = 0.3f;
	_scale.y = 0.3f;
	_position.x = 0;
	_position.y = 0;
	_visible = false;
	//cout << _position.x << " " << _position.y << endl;
}

void NewDude::Update()
{
	ganggogo += Time::deltaTime * 5;
	ypos = cos(ganggogo) * 10;
	_position.x += ypos;
	_position.y += 5;

	if (_position.y > 900)
	{
		_visible = false;
	}
}

void NewDudeMNG::CreateNewDude()
{
	for (int i = 0; i < 30; i++)
	{
		NewDude* dude = new NewDude();
		newdud.push_back(dude);
	}
}

void NewDudeMNG::ComeOutDude()
{
	for (auto it : newdud)
	{
		if (it->_visible == false)
		{
			it->_visible = true;
			it->_position.y = 0;
			it->_position.x = (rand() % 1234 + 44);
			return;
		}
	}
}
