#include "DXUT.h"
#include "Sprite.h"

Sprite::Sprite()
{
	texture = nullptr;
	Aninum = 0;
	Timer = 0;
	NowFrame = 0;
}

Sprite::~Sprite()
{
	Renderer::GetInstance()->RemoveRenderTarget(this);
}

void Sprite::Create(wstring filename)
{
	texture = TextureManager::GetInstance()->LoadTexture(filename);
	AddRenderTarget();
}

void Sprite::AddRenderTarget()
{
	Renderer::GetInstance()->AddRenderTarget(this);
}

bool Sprite::Animation(wstring path, int frame, float delay, int Aninum)
{
	Timer += Time::deltaTime;
	if (Timer >= delay)
	{
		if (this->Aninum != Aninum)
		{
			this->Aninum = Aninum;
			NowFrame = 0;
		}
		if (NowFrame == frame)
		{
			NowFrame = 0;
			return true;
		}
		NowFrame++;

		auto route = path + to_wstring(NowFrame) + L".png";
		Create(route);

		Timer = 0;
	}
	return false;
}

RECT Sprite::GetRect()
{
	RECT r = { 0,0,0,0 };
	r.right = _position.x + texture->_info.Width / 2 * _scale.x;
	r.left = _position.x - texture->_info.Width / 2 * _scale.x;
	r.top = _position.y - texture->_info.Height / 2 * _scale.y;
	r.bottom = _position.y + texture->_info.Height / 2 * _scale.y;

	return r;
}

bool Sprite::GoTo(vector2 EndPos, float Speed)
{
	vector2 v = EndPos - _position;
	float l = sqrt(v.x * v.x + v.y * v.y);

	if (l < 10)
		return true;
	v.x /= l;
	v.y /= l;
	_rotation = atan2(v.y, v.x);

	_position += v * Speed * Time::deltaTime;
	return false;
}

void Sprite::Draw()
{
	if (!_visible)
		return;
	if (texture == nullptr)
		return;

	Director::GetInstance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Director::GetInstance()->GetSprite()->SetTransform(&GetMatrix());
	D3DXVECTOR3 center = { texture->_info.Width * _pivot.x,texture->_info.Height * _pivot.y,0 };
	Director::GetInstance()->GetSprite()->Draw(texture->_texture, nullptr, &center, nullptr, _color);
	Director::GetInstance()->GetSprite()->End();
}
