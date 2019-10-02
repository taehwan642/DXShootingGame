#pragma once
#include "Sprite.h"

class Health :
	public Sprite
{
public:
	Health();
	void HealthChanger();
};

class HealthMNG : public Singleton<HealthMNG>
{
public:
	int nHealth;

	void HealthCountDown();
	void HealthMinus();
	vector<Health*> vechealt;
};