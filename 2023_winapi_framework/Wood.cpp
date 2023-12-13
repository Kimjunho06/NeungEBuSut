#include "pch.h"
#include "Wood.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"
#include "Collider.h"

Wood::Wood()
	: texture(nullptr)
	, isSlothWood(false)
{
	texture = ResMgr::GetInst()->TexLoad(L"Wood", L"Texture\\Wood.bmp");
	Vec2 vPos = GetPos();

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.7f, 256.f * 0.1f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x + 120, vPos.y - 100));
}

Wood::~Wood()
{
}

void Wood::Update()
{

}

void Wood::Render(HDC _dc)
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

void Wood::EnterCollision(Collider* _pOther)
{

}
