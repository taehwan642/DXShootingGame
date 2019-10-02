#include "DXUT.h"
#include "Node.h"

Node::Node()
{
	_position = { 0,0 };
	_scale = { 1,1 };
	_pivot = { 0.5f,0.5f };
	_visible = true;
	_color = 0xffffffff;
	_rotation = 0.0f;
	_parent = nullptr;
}

D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	D3DXMatrixTransformation2D(&m, nullptr, 0, &_scale, nullptr, _rotation, &_position);

	if (_parent)
	{
		m *= _parent->GetMatrix();
	}

	return m;
}

void Node::AddChild(Node* child,int layer)
{
	_layer = layer;
	child->_parent = this;
}
