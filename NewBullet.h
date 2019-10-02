#pragma once
#include "Sprite.h"
#include <math.h>
class NewBullet :
	public Sprite
{
public:
	NewBullet();
	float pi;
	void InitDirectedBullet(
		float ex, float ey,
		float& x, float& y,
		float& vx, float& vy,
		float speed, float theta);
	void MoveDirectedBullet(
		float& x, float& y,
		float vx, float vy
	);
};

