#include "pch.h"
#include "SeaOtter.h"
#include "Collider.h"
#include "CollisionMgr.h"
#include "EventMgr.h"
#include "ResMgr.h"
#include "Animation.h"
#include "Animator.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

SeaOtter::SeaOtter()
	: texture(nullptr)
	, hitTime(3.f)
	, isHit(false)
{
	texture = ResMgr::GetInst()->TexLoad(L"SeaOtter", L"Texture\\SeaOtterSheet.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"SeaOtter_idle", texture, Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 0.2f);
	GetAnimator()->CreateAnim(L"SeaOtter_hit", texture, Vec2(512.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);
	GetAnimator()->PlayAnim(L"SeaOtter_idle", true);

}

SeaOtter::~SeaOtter()
{

}

void SeaOtter::Update()
{
	GetAnimator()->Update();

	hitTime += fDT;
	if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
		if (hitTime < 0.3) return;
		GetAnimator()->PlayAnim(L"SeaOtter_hit", false);
		hitTime = 0;
	}
	else {
		if (hitTime < 0.2) return;
		GetAnimator()->PlayAnim(L"SeaOtter_idle", false);
	}
}

void SeaOtter::Render(HDC _dc)
{
	Component_Render(_dc);

}
