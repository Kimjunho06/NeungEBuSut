#include "pch.h"
#include "Crocodile.h"
#include "Collider.h"
#include "CollisionMgr.h"
#include "EventMgr.h"
#include "ResMgr.h"
#include "Animation.h"
#include "Animator.h"
#include "KeyMgr.h"
#include "TimeMgr.h"

Crocodile::Crocodile()
	: texture(nullptr)
	, biteTime(3.f)
	, isBite(false)
{
	Vec2 vPos = GetPos();

	texture = ResMgr::GetInst()->TexLoad(L"Crocodile", L"Texture\\Crocodile.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Crocodile_idle", texture, Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 0.2f);
	GetAnimator()->CreateAnim(L"Crocodile_bite", texture, Vec2(512.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);
	GetAnimator()->PlayAnim(L"Crocodile_idle", true);

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.05f, 256.f * 0.15f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x, vPos.y + 80));

}

Crocodile::~Crocodile()
{
}

void Crocodile::Update()
{
	GetAnimator()->Update();

	biteTime += fDT;
	if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
		if (biteTime < 1.5) return;
		GetAnimator()->PlayAnim(L"Crocodile_bite", false);
		biteTime = 0;
		isBite = true;
	}
	else {
		if (biteTime < 1) return;
		GetAnimator()->PlayAnim(L"Crocodile_idle", false);
		isBite = false;
	}
}

void Crocodile::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Crocodile::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Fish")
	{
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			EventMgr::GetInst()->ChangeScene(L"Stage_4");
		}
		//SceneMgr::GetInst()->LoadScene(L"Stage_1");
	}
}

void Crocodile::StayCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Fish" && !isBite)
	{
		if (KEY_DOWN(KEY_TYPE::LBUTTON) ) {
			EventMgr::GetInst()->ChangeScene(L"Stage_4");
		}
		//SceneMgr::GetInst()->LoadScene(L"Stage_1");
	}
}
