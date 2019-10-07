#pragma once
#include "Sprite.h"
#include "Health.h"
#include "Hero.h"
//One Day, Im going to Add Strategy Pattern in this ITEM.
class HealItem : public Sprite
{
public:
	HealItem();
	void Update() override;
	void DoHeal();
};

//class AttackItem : public Sprite
//{
//	
//};

class ItemMNG : public Singleton<ItemMNG>
{
public:
	HealItem* healitem;
	vector<HealItem*> heals;
	void CreateHealItem();
};
