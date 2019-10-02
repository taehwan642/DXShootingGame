#pragma once
#include "Node.h"
#include "Sprite.h"
class Font :
	public Node
{
public:
	vector<Sprite*> sp;
	void Create_font(int num, vector2 vec);
	void Delete_Font();
	int Addpos;
};

