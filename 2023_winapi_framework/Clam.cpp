#include "pch.h"
#include "Clam.h"
#include "ResMgr.h"
#include "Animation.h"
#include "Animator.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "TimeMgr.h"

Clam::Clam()
	: texture(nullptr)
	, hitTime(3.f)
	, cnt(0)
	, isHit(false)
{
	texture = ResMgr::GetInst()->TexLoad(L"Clam", L"Texture\\Shell.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Clam_1", texture, Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 0.2f);
	GetAnimator()->CreateAnim(L"Clam_2", texture, Vec2(512.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);
	GetAnimator()->CreateAnim(L"Clam_3", texture, Vec2(1024.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);	
	GetAnimator()->CreateAnim(L"Clam_4", texture, Vec2(1536.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);
	GetAnimator()->PlayAnim(L"Clam_1", true);
}

Clam::~Clam()
{
}

void Clam::Update()
{
	GetAnimator()->Update();

	Vec2 vPos = GetPos();

	Vec2 vMovePos = Vec2(20.f, 60.f);

	hitTime += fDT;
	if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
		if (hitTime < 0.3) return;
		vPos = vPos + vMovePos;
		cnt++;
		hitTime = 0;
		isHit = true;
	}
	else {
		if (hitTime < 0.2) return;
		if (isHit) {
			vPos = vPos - vMovePos;
			isHit = false;
		}
	}

	SetPos(vPos);

	if (cnt >= 16) {
		GetAnimator()->PlayAnim(L"Clam_4", true);
		EventMgr::GetInst()->ChangeScene(L"Stage_5");
	}
	else if(cnt >= 12)
		GetAnimator()->PlayAnim(L"Clam_3", true);
	else if(cnt >= 8)
		GetAnimator()->PlayAnim(L"Clam_2", true);
	else if (cnt >= 4)
		GetAnimator()->PlayAnim(L"Clam_1", true);
}

void Clam::Render(HDC _dc)
{
	Component_Render(_dc);
}
