#include "pch.h"
#include "Turtle.h"
#include "ResMgr.h"
#include "Animation.h"
#include "Animator.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Collider.h"
#include "Texture.h"
#include "EventMgr.h"

Turtle::Turtle()
	: texture(nullptr)
	, speed(1)
{
	Vec2 vPos = GetPos();
	texture = ResMgr::GetInst()->TexLoad(L"Turtle", L"Texture\\TurtleSheet.bmp"); // 2048 / 4 = 512.512

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Turtle_move", texture, Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 4, 0.2f);
	GetAnimator()->PlayAnim(L"Turtle_move", true);

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.2f, 256.f * 0.3f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x, vPos.y + 40));
}

Turtle::~Turtle()
{

}

void Turtle::Update()
{
	GetAnimator()->Update();

	Vec2 vPos = GetPos();
	
	if (IsClickAble(this)) {
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			speed *= 2;
		}
	}

	vPos.x += fDT * speed;

	SetPos(vPos);
}

void Turtle::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Turtle::EnterCollision(Collider* _pOther) {
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Flag")
	{
		EventMgr::GetInst()->ChangeScene(L"Stage_1");
		//SceneMgr::GetInst()->LoadScene(L"Stage_1");
	}
}