#pragma once
#include "Sprite.h"

class Mover :
	public Sprite
{
public:
	virtual void Move() = 0;
};

class StaticMove : public Mover
{
public:
	void Move() override;
};

class DynamicMove : public Mover
{
public:
	void Move() override;
};

class MoveSettings
{
public:
	MoveSettings();
	~MoveSettings();
	void MoveGo();
	void MoveSet(Mover* mv);
private:
	Mover* p_mv;
};