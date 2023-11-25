#include "pch.h"
#include "ResMgr.h"
#include "Texture.h"
#include "TestButton.h"

TestButton::TestButton()
	: texture(nullptr)
{
	texture = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\jiwoo.bmp");
}

TestButton::~TestButton()
{
}

void TestButton::Init()
{
}

void TestButton::Update()
{

}

void TestButton::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = texture->GetWidth();
	int Height = texture->GetHeight();
	BitBlt(_dc
		,(int)(vPos.x - vScale.x /2)
		,(int)(vPos.y - vScale.y /2)
		, Width,Height, texture->GetDC()
		,0,0,SRCCOPY);
}

void TestButton::OnClickEvent()
{

}
