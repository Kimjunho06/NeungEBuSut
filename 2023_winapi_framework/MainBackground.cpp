#include "pch.h"
#include "MainBackground.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Texture.h"
#include "Core.h"

MainBackground::MainBackground() : texture(nullptr)
{
	texture = ResMgr::GetInst()->TexLoad(L"StartSceneBackground", L"Texture\\StartSceneBackground.bmp");
}

MainBackground::~MainBackground()
{
}

void MainBackground::Update()
{
    if (IsClickAble(this) && !Core::GetInst()->isExitOnButton) // 클릭 됐는가
    {
        if (KEY_DOWN(KEY_TYPE::LBUTTON)) // 좌측 마우스 버튼으로 클릭했는가
        {
			Core::GetInst()->isGameStart = true;
			ResMgr::GetInst()->Stop(SOUND_CHANNEL::BGM);
            SceneMgr::GetInst()->LoadScene(L"Stage_1");
        }
    }
}

void MainBackground::Render(HDC _dc)
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
