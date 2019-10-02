#pragma once
#include "Sprite.h"
class NewDude : public Sprite
{
public:
	NewDude();
	void Update() override;
	float ypos;
	float ganggogo;
};

class NewDudeMNG : public Singleton<NewDudeMNG>
{
public:
	void CreateNewDude();
	void ComeOutDude();
	vector<NewDude*> newdud;
};