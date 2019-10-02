#include "DXUT.h"
#include "Director.h"
#include "Renderer.h"
LPD3DXSPRITE Director::_sprite;

bool Director::OnMouseDown()
{
	if (ClickNum == 1)
	{
		ClickNum++;
		return true;
	}
	return false;
}

bool Director::OnMouse()
{
	if (ClickNum == 2)
	{
		return true;
	}
	return false;
}

bool Director::OnMouseUp()
{
	if (ClickNum == 3)
	{
		ClickNum = -1;
		return true;
	}
	return false;
}

void Director::Init()
{
	ClickNum = 0;
	_sprite = nullptr;
	_currentScene = nullptr;

	D3DXCreateSprite(DXUTGetD3D9Device(),&_sprite);
}

void Director::Update()
{
	if (_currentScene)
		_currentScene->Update();
	Renderer::GetInstance()->Render();
	
	GetCursorPos(&p);
	ScreenToClient(DXUTGetHWND(), &p);
}

void Director::ChangeScene(Scene* scene)
{
	if (_currentScene)
		_currentScene->OnExit();
	_currentScene = scene;
	_currentScene->Init();
}

vector2 Director::GetMousePos()
{
	vector2 v = { (float)p.x,(float)p.y };
	return v;
}
