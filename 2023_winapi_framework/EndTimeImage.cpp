#include "pch.h"
#include "EndTimeImage.h"
#include "Core.h"
#include "ResMgr.h"
#include "Texture.h"

EndTimeImage::EndTimeImage()
	: texture(nullptr)
{
	texture = ResMgr::GetInst()->TexLoad(L"EndTimeImage", L"Texture\\OverIcon.bmp");
}

EndTimeImage::~EndTimeImage()
{
}

void EndTimeImage::Update()
{
}

void EndTimeImage::Render(HDC _dc)
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

	DeleteDC(alphaDC);
	DeleteObject(alphabit);
}

void EndTimeImage::OnClickEvent()
{
}
