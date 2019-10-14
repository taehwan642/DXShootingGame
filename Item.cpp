#include "DXUT.h"
#include "Item.h"
HealItem::HealItem()
{
	Create(L"ITEM.png");
	_visible = false;
	_scale = { 0.2f,0.2f };
}

void HealItem::Update()
{
	_position.y += 3;
	DoHeal();
	if (_position.y > 900)
	{
		_visible = false;
	}
}

void HealItem::DoHeal()
{
	RECT hr;
	if (IntersectRect(&hr, &GetRect(), &HeroMNG::GetInstance()->hero->GetRect()))
	{
		HealthMNG::GetInstance()->HealthUp();
		_visible = false;
		_position = { 123123, 123123 };
		return;
	}
}

void ItemMNG::CreateHealItem()
{
	for (int i = 0; i < 30; i++)
	{
		healitem = new HealItem();
		heals.push_back(healitem);
	}
}
