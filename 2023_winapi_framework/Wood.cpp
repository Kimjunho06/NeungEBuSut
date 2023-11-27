#include "pch.h"
#include "Wood.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"

Wood::Wood()
	: texture(nullptr)
{
	texture = ResMgr::GetInst()->TexLoad(L"Wood", L"Texture\\Wood.bmp");
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
	int Width = texture->GetWidth();
	int Height = texture->GetHeight();

	HDC alphaDC = CreateCompatibleDC(_dc);
	HBITMAP alphabit = CreateCompatibleBitmap(_dc, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
	SelectObject(alphaDC, alphabit);

	PatBlt(alphaDC, 0, 0, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y, WHITENESS);

	StretchBlt(alphaDC
		, 0
		, 0
		, Width, Height, texture->GetDC()
		, 0
		, 0
		, Width
		, Height
		, SRCCOPY);

	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, alphaDC
		, 0, 0, Width, Height, RGB(255, 0, 255));


	DeleteDC(alphaDC);
	DeleteObject(alphabit);
}
