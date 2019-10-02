#pragma once
#include "Type.h"
#include "Node.h"
class Renderer : public Singleton<Renderer>
{
public:
	void Render();
	void AddRenderTarget(Node* node);
	void RemoveRenderTarget(Node* node);
private:
	list<Node*> _rendertargets;
	static bool Comp(Node* a, Node* b);
};

