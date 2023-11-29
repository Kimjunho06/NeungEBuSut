#include "pch.h"
#include "ColorObject.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"

ColorObject::ColorObject()
	: textures{ nullptr }
	, colorIdx(0)
{
	textures.resize(3); // if Chameleon Obj increase, resize Chameleon Obj Cnt

	colorIdx = rand() % textures.size();

	textures[0] = ResMgr::GetInst()->TexLoad(L"Chameleon_blue_color", L"Texture\\ColorCircle_blue.bmp");
	textures[1] = ResMgr::GetInst()->TexLoad(L"Chameleon_green_color", L"Texture\\ColorCircle_green.bmp");
	textures[2] = ResMgr::GetInst()->TexLoad(L"Chameleon_red_color", L"Texture\\ColorCircle_red.bmp");

}

ColorObject::~ColorObject()
{
	
}

void ColorObject::Update()
{

}

void ColorObject::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vScaleOffset = GetScaleOffset();
	int Width = textures[colorIdx]->GetWidth();
	int Height = textures[colorIdx]->GetHeight();

	HDC alphaDC = CreateCompatibleDC(_dc);
	HBITMAP alphabit = CreateCompatibleBitmap(_dc, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
	SelectObject(alphaDC, alphabit);

	PatBlt(alphaDC, 0, 0, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y, WHITENESS);

	StretchBlt(alphaDC
		, 0
		, 0
		, Width * vScaleOffset.x, Height * vScaleOffset.y, textures[colorIdx]->GetDC()
		, 0
		, 0
		, Width
		, Height
		, SRCCOPY);

	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width * vScaleOffset.x, Height * vScaleOffset.y, alphaDC
		, 0, 0, Width * vScaleOffset.x, Height * vScaleOffset.y, RGB(255, 0, 255));


	DeleteDC(alphaDC);
	DeleteObject(alphabit);
}
