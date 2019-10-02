#pragma once
#include "Node.h"
class Scene : public Node
{
public:
	virtual void Init() {};
	virtual void Update() {};
	virtual void OnExit() {};
};

