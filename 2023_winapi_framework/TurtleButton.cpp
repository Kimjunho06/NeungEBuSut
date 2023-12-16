#include "pch.h"
#include "TurtleButton.h"
#include "KeyMgr.h"
#include "Texture.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Core.h"


TurtleButton::TurtleButton()
	: texture(nullptr)
	, speed(1)
{
	texture = ResMgr::GetInst()->TexLoad(L"TurtleButton", L"Texture\\TurtleButton.bmp"); 
}

TurtleButton::~TurtleButton()
{
}

void TurtleButton::Update()
{
	if (IsClickAble(this)) {
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			OnClickEvent();
		}
	}
}

void TurtleButton::Render(HDC _dc)
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

void TurtleButton::OnClickEvent()
{
	speed *= 1.3f;
}
