#include "pch.h"
#include "StageBackground.h"
#include "ResMgr.h"

StageBackground::StageBackground()
{
	texture = ResMgr::GetInst()->TexLoad(L"Background", L"Texture\\Background.bmp");
}

StageBackground::~StageBackground()
{
}

void StageBackground::Update()
{
}

void StageBackground::Render(HDC _dc)
{
	Component_Render(_dc);
}
