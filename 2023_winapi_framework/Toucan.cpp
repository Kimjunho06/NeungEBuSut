#include "pch.h"
#include "Toucan.h"
#include "ResMgr.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "Animator.h"
#include "Animation.h"

Toucan::Toucan() : texture(nullptr), isOpenBeak(false)
{
	// 텍스처 받아오기
	texture = ResMgr::GetInst()->TexLoad(L"Toucan.bmp", L"Texture\\Toucan.bmp");
	
	// 애니메이션 세팅
	CreateAnimator();
	GetAnimator()->CreateAnim(L"Toucan_CloseBeak", texture, Vec2(0.f,0.f), Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 5.f);
}

Toucan::~Toucan()
{

}

void Toucan::Update()
{

}

void Toucan::Render(HDC _dc)
{

}
