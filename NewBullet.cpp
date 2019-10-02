#include "DXUT.h"
#include "NewBullet.h"

NewBullet::NewBullet()
{
	Create(L"SPIT.png");
	_visible = true;
	_position.x = 600;
	_position.y = 600;
	pi = 3.141592;
}

void NewBullet::InitDirectedBullet(float ex, float ey, float& x, float& y, float& vx, float& vy, float speed, float theta)
{
	x = ex;
	y = ey;
	vx = cos(pi / 180 * theta) * speed;
	vy = sin(pi / 180 * theta) * speed;
}

void NewBullet::MoveDirectedBullet(float& x, float& y, float vx, float vy)
{
	x += vx;
	y += vy;
}
