#include "DXUT.h"
#include "BackGround.h"

BackGround::BackGround()
{
	s1 = new Sprite();
	s1->Create(L"BG.png");
	s1->_visible = true;
	s1->_position = { 0, 0 };
	s1->_pivot = { 0, 0 };

	s2 = new Sprite();
	s2->Create(L"BG.png");
	s2->_visible = true;
	s2->_position = { 0, -720 };
	s2->_pivot = { 0, 0 };
	AddRenderTarget();
}
//X : 640.5Y : 360.5
//배열ㄹ로 코드 줄이기
void BackGround::Update()
{

	if (s1->_position.y > 714)
	{
		s1->_position.y = -720; 
	}


	if (s2->_position.y > 714)
	{
		s2->_position.y = -720;
	}

		s1->_position.y += 5;
		s2->_position.y += 5;

	cout << "X : " << _position.x << "Y : " << _position.y << endl;
}

void BackGroundMNG::BackGroundCreate()
{
	bg = new BackGround();
}
