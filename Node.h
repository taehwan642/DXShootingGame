#pragma once
class Node
{
public:
	Node();
	virtual ~Node() {};

	vector2 _position;
	vector2 _scale;
	vector2 _pivot;
	float _rotation;
	bool _visible;
	COLOR _color;
	Node* _parent;
	int _layer;
	D3DXMATRIX GetMatrix();

	void AddChild(Node* child,int layer);

	virtual void Draw() {};
	virtual void Update() {};
};

