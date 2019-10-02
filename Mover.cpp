#include "DXUT.h"
#include "Mover.h"

void StaticMove::Move()
{
	_position.y += 50.f;
}

void DynamicMove::Move()
{

}

MoveSettings::MoveSettings() : p_mv(0)
{

}

MoveSettings::~MoveSettings()
{
	if (p_mv) delete p_mv;
}

void MoveSettings::MoveGo()
{
	p_mv->Move();
}

void MoveSettings::MoveSet(Mover* mv)
{
	if (p_mv) delete p_mv;
	p_mv = mv;
}
