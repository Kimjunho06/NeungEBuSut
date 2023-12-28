#include "pch.h"
#include "ExitButton.h"
#include "Core.h"
#include "ResMgr.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventMgr.h"

ExitButton::ExitButton()
{
	texture[0] = ResMgr::GetInst()->TexLoad(L"ExitButton", L"Texture\\ExitButton_X.bmp");
	texture[1] = ResMgr::GetInst()->TexLoad(L"ExitButton2", L"Texture\\StageExitButton.bmp");
}

ExitButton::~ExitButton()
{
}

void ExitButton::Update()
{
	if (Core::GetInst()->isExitOnButton)
		Core::GetInst()->isExitOnButton = false;
	if (IsClickAble(this)) {
		Core::GetInst()->isExitOnButton = true;
		if (KEY_DOWN(KEY_TYPE::LBUTTON))
		{
			OnClickEvent();
		}
	}
}

void ExitButton::Render(HDC _dc)
{
	if (!Core::GetInst()->isGameStart) {

		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();
		Vec2 vScaleOffset = GetScaleOffset();
		int Width = texture[0]->GetWidth();
		int Height = texture[0]->GetHeight();

		HDC alphaDC = CreateCompatibleDC(_dc);
		HBITMAP alphabit = CreateCompatibleBitmap(_dc, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
		SelectObject(alphaDC, alphabit);

		PatBlt(alphaDC, 0, 0, Core::GetInst()->GetResolution().x,	Core::GetInst()->GetResolution().y, WHITENESS);

		StretchBlt(alphaDC
			, 0
			, 0
			, Width * vScaleOffset.x
			, Height * vScaleOffset.y
			, texture[0]->GetDC()
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
	else {
		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();
		Vec2 vScaleOffset = GetScaleOffset();
		int Width = texture[1]->GetWidth();
		int Height = texture[1]->GetHeight();

		HDC alphaDC = CreateCompatibleDC(_dc);
		HBITMAP alphabit = CreateCompatibleBitmap(_dc, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
		SelectObject(alphaDC, alphabit);

		PatBlt(alphaDC, 0, 0, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y, WHITENESS);

		StretchBlt(alphaDC
			, 0
			, 0
			, Width * vScaleOffset.x
			, Height * vScaleOffset.y
			, texture[1]->GetDC()
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
}

void ExitButton::OnClickEvent()
{
	if (Core::GetInst()->isGameStart) {
		EventMgr::GetInst()->ChangeScene(L"MainScene");
		Core::GetInst()->isGameStart = false;
		Core::GetInst()->gameTime = 0;
	}
	else {
		PostQuitMessage(0);
	}
}
