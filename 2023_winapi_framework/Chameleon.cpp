#include "pch.h"
#include "Chameleon.h"
#include "define.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"

Chameleon::Chameleon()
	: textures{nullptr}
	, colorIdx(0)
{
	textures.resize(3); // if Chameleon Obj increase, resize Chameleon Obj Cnt
	
	colorIdx = rand() % textures.size();

	textures[0] = ResMgr::GetInst()->TexLoad(L"Chameleon_blue", L"Texture\\Chameleon_blue.bmp");
	textures[1] = ResMgr::GetInst()->TexLoad(L"Chameleon_green", L"Texture\\Chameleon_green.bmp");
	textures[2] = ResMgr::GetInst()->TexLoad(L"Chameleon_red", L"Texture\\Chameleon_red.bmp");
	
	// 랜덤 값 넘기기
	// 텍스쳐 업로드
}

Chameleon::~Chameleon()
{
	
}

void Chameleon::Update()
{
	if (IsClickAble(this)) {
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			colorIdx++;
			if (colorIdx >= textures.size()) {
				colorIdx = 0;
			}
		}
	}
}

void Chameleon::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = textures[colorIdx]->GetWidth();
	int Height = textures[colorIdx]->GetHeight();

	HDC alphaDC = CreateCompatibleDC(_dc);
	HBITMAP alphabit = CreateCompatibleBitmap(_dc, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
	SelectObject(alphaDC, alphabit);

	PatBlt(alphaDC, 0, 0, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y, WHITENESS);

	StretchBlt(alphaDC
		, 0
		, 0
		, Width * 0.3, Height * 0.3, textures[colorIdx]->GetDC()
		, 0
		, 0
		, Width
		, Height
		, SRCCOPY);

	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width * 0.3, Height * 0.3, alphaDC
		, 0, 0, Width * 0.3, Height * 0.3, RGB(255, 0, 255));


	DeleteDC(alphaDC);
	DeleteObject(alphabit);
}
