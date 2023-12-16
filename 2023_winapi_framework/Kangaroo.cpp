#include "pch.h"
#include "Kangaroo.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Collider.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"

Kangaroo::Kangaroo()
	: texture(nullptr)
	, isCanJump(false)
	, isJump(false)
	, isfall(true)
	, isDie(false)
	, jumpTime(0)
{
	Vec2 vPos = GetPos();
	texture = ResMgr::GetInst()->TexLoad(L"Kangaroo", L"Texture\\Kangaroo.bmp"); // 2048 / 4 = 512.512

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Kangaroo_move", texture, Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 4, 0.2f);
	GetAnimator()->PlayAnim(L"Kangaroo_move", true);

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.1f, 256.f * 0.3f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x, vPos.y + 10));
}

Kangaroo::~Kangaroo()
{
}

void Kangaroo::Update()
{
	GetAnimator()->Update();
	Vec2 vPos = GetPos();
	if (KEY_DOWN(KEY_TYPE::SPACE) && isCanJump) {
		isJump = true;
		isCanJump = false;
	}

	if (isJump) {
		vPos.y -= 3.5f;
		jumpTime += fDT;
		if (jumpTime > 0.5f) {
			isJump = false;
			isfall = true;
		}
	}

	if (isfall) {
		vPos.y += 6.f;
	}
	SetPos(vPos);
}

void Kangaroo::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Kangaroo::StayCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Ground") {
		isCanJump = true;
		isJump = false;
		isfall = false;
		jumpTime = 0;
	}
}

void Kangaroo::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	Vec2 vColPos = pOtherObj->GetPos();
	Vec2 vColScale = pOtherObj->GetScale();

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	vPos.y = (vColPos.y - vColScale.y / 2) - 16;

	SetPos(vPos);

	if (pOtherObj->GetName() == L"Rock") {
		isDie = true;
	}
	
	if (pOtherObj->GetName() == L"Flag") {
		EventMgr::GetInst()->ChangeScene(L"Stage_9");
	}
}
