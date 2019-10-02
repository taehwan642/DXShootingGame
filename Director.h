#pragma once
#include "Type.h"
#include "Scene.h"
//#include "Renderer.h"
class Director : public Singleton<Director>
{
public:
	int ClickNum;

	bool OnMouseDown();
	bool OnMouse();
	bool OnMouseUp();

	void Init();
	void Update();

	void ChangeScene(Scene* scene);

	LPD3DXSPRITE GetSprite() { return _sprite; };

	vector2 GetMousePos();
	POINT p;
private:
	static LPD3DXSPRITE _sprite;
	Scene* _currentScene;
};

