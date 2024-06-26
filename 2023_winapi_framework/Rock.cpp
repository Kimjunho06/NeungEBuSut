#include "pch.h"
#include "Rock.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "EventMgr.h"

Rock::Rock()
	: texture(nullptr)
	, isKangarooRock(false)
	, speed(600)
{
	Vec2 vPos = GetPos();
	texture = ResMgr::GetInst()->TexLoad(L"Rock", L"Texture\\Rock.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.1f, 256.f * 0.3f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x, vPos.y));
}

Rock::~Rock()
{

}

void Rock::Update()
{
	if (!isKangarooRock) return;
	Vec2 vPos = GetPos();

	vPos.x += fDT * -speed;

	SetPos(vPos);
}

void Rock::Render(HDC _dc)
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
