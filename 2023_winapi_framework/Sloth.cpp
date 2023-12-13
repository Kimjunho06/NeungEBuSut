#include "pch.h"
#include "Sloth.h"
#include "ResMgr.h"	
#include "Animator.h"	
#include "KeyMgr.h"	
#include "Core.h"	
#include "Collider.h"	

Sloth::Sloth()
	: texture(nullptr)
	, isDrag(false)
	, isHang(false)
	, dragStartPos{}
{
	texture = ResMgr::GetInst()->TexLoad(L"Sloth", L"Texture\\Sloth.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Sloth_idle", texture, Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 0.2f);
	GetAnimator()->CreateAnim(L"Sloth_hang", texture, Vec2(512.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);
	GetAnimator()->PlayAnim(L"Sloth_idle", true);

	Vec2 vPos = GetPos();

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.2f, 256.f * 0.2f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x, vPos.y));
}

Sloth::~Sloth()
{

}

void Sloth::Update()
{
	if (!isHang) {
		GetAnimator()->PlayAnim(L"Sloth_idle", true);

		Vec2 vPos = GetPos();
		POINT mousePos = KeyMgr::GetInst()->GetMousePos();

		if (IsClickAble(this) && !Core::GetInst()->isDragging) {
			if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
				isDrag = true;
				Core::GetInst()->isDragging = true;
				dragStartPos = vPos;
			}
		}
		if (KEY_UP(KEY_TYPE::LBUTTON) && isDrag) {
			Core::GetInst()->isDragging = false;
			isDrag = false;
		}

		if (isDrag) {
			vPos = (Vec2)mousePos;
		}

		SetPos(vPos);
	}
	else {
		GetAnimator()->PlayAnim(L"Sloth_hang", true);
	}
	GetAnimator()->Update();
}

void Sloth::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Sloth::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Wood") 
	{
		isHang = true;
		Core::GetInst()->isDragging = false;
	}
}
