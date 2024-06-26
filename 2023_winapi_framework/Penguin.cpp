#include "pch.h"
#include "Penguin.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Texture.h"
#include "TimeMgr.h"
#include "Core.h"

Penguin::Penguin()
	: texture(nullptr)
	, isClick(false)
	, speed(0)
{
	texture = ResMgr::GetInst()->TexLoad(L"Penguin", L"Texture\\Penguin.bmp");

	speed = -((rand() % 400) + 800);
}

Penguin::~Penguin()
{
}

void Penguin::Update()
{
	if (!isClick) {
		Vec2 vPos = GetPos();
		POINT resolution = Core::GetInst()->GetResolution();
		int offset = 80;

		if (vPos.x <= offset) {
			vPos.x = Core::GetInst()->GetResolution().x / 2 + 180;
			speed = -((rand() % 400) + 800);
		}
		vPos.x += speed * fDT;

		SetPos(vPos);
	}

	if (IsClickAble(this)) {
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			isClick = true;
		}
	}
}

void Penguin::Render(HDC _dc)
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
