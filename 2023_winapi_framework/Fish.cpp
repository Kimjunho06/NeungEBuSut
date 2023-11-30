#include "pch.h"
#include "Fish.h"
#include "ResMgr.h"
#include "Collider.h"
#include "CollisionMgr.h"
#include "Texture.h"
#include "Core.h"

Fish::Fish()
	: texture(nullptr)
	, speed(2)
	, dir(DIRECTION::RIGHT)
{
	Vec2 vPos = GetPos();

	texture = ResMgr::GetInst()->TexLoad(L"Fish", L"Texture\\Fish.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.05f, 256.f * 0.15f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x, vPos.y - 40));
}

Fish::~Fish()
{

}

void Fish::Update()
{
	Vec2 vPos = GetPos();
	POINT resolution = Core::GetInst()->GetResolution();
	int offset = 60;

	if (vPos.x >= resolution.x - offset) {
		dir = DIRECTION::LEFT;
	}
	else if (vPos.x <= offset) {
		dir = DIRECTION::RIGHT;
	}
	vPos.x += speed * (int)dir;

	SetPos(vPos);

}

void Fish::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vScaleOffset = GetScaleOffset();
	int Width = texture->GetWidth();
	int Height = texture->GetHeight();

	HDC alphaDC = CreateCompatibleDC(_dc);
	HBITMAP alphabit = CreateCompatibleBitmap(_dc, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
	SelectObject(alphaDC, alphabit);

	PatBlt(alphaDC, 0, 0, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y, WHITENESS);

	StretchBlt(alphaDC
		, 0
		, 0
		, Width * vScaleOffset.x
		, Height * vScaleOffset.y
		, texture->GetDC()
		, 0
		, 0
		, Width
		, Height
		, SRCCOPY);

	TransparentBlt(_dc
		, (int)(vPos.x - Height * vScaleOffset.x / 2.f)
		, (int)(vPos.y - Width * vScaleOffset.y / 2.f)
		, Width * vScaleOffset.x
		, Height * vScaleOffset.y
		, alphaDC
		, 0
		, 0
		, Width * vScaleOffset.x
		, Height * vScaleOffset.y
		, RGB(255, 0, 255));

	Component_Render(_dc);
	DeleteDC(alphaDC);
	DeleteObject(alphabit);
}
