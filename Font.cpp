#include "DXUT.h"
#include "Font.h"

void Font::Create_font(int str, vector2 vec)
{
	Delete_Font();

	Addpos = 0;
	_position = vec;

	for (auto it : to_wstring(str)) 
	{
		Sprite* s = new Sprite;
		s->Create(L"font/" + to_wstring(it - 48) + L".png");
		s->_position = { Addpos + _position.x,_position.y };
		Addpos += 25;
		sp.push_back(s);
	}
}

void Font::Delete_Font()
{
	for (auto it : sp)
	{
		delete it;
	}
	sp.clear();
}
