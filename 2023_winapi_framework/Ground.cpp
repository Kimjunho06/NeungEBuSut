#include "pch.h"
#include "Ground.h"
#include "Collider.h"

Ground::Ground()
{
	Vec2 vPos = GetPos();

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.2f, 256.f * 0.3f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x, vPos.y));
}

Ground::~Ground()
{
}

void Ground::Update()
{
}

void Ground::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Ground::EnterCollision(Collider* _pOther)
{
}
