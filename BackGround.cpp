#include "DXUT.h"
#include "BackGround.h"

BackGround::BackGround()
{
	for (int i = 0; i < 2; i++)
	{
		sp[i] = new Sprite();
		sp[i]->Create(L"BG.png");
		sp[i]->_visible = true;
		sp[i]->_pivot = { 0, 0 };
	}
	sp[0]->_position = { 0,0 };
	sp[1]->_position = { 0,-720 };
	AddRenderTarget();
}
//X : 640.5Y : 360.5
void BackGround::Update()
{
	for (int i = 0; i < 2; i++)
	{
		if (sp[i]->_position.y > 714)
		{
			sp[i]->_position.y = -720;
		}

		sp[i]->_position.y += 5.5f;
	}
}

void BackGroundMNG::BackGroundCreate()
{
	bg = new BackGround();
}
