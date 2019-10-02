#pragma once
#include "Node.h"
#include "Renderer.h"
#include "Director.h"
#include "Texture.h"
class Sprite :
	public Node
{
public:
	Sprite();
	~Sprite();

	void Create(wstring filename);
	void AddRenderTarget();

	bool Animation(wstring path, int frame, float delat, int Aninum);
	int NowFrame;
	float Timer;
	int Aninum;

	RECT GetRect();

	bool GoTo(vector2 EndPos, float Speed);

	Texture2D * texture;


	void Draw() override;
};

