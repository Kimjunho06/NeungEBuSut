#include "pch.h"
#include "Capybara.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "Core.h"

Capybara::Capybara()
	: texture(nullptr)
	, isDrag(false)
	, dragStartPos{}
{
	texture = ResMgr::GetInst()->TexLoad(L"Capybara", L"Texture\\CapybaraSheet.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Capybara_idle", texture, Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 0.2f);
	GetAnimator()->CreateAnim(L"Capybara_Stand", texture, Vec2(512.f, 0.f), Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);
	GetAnimator()->PlayAnim(L"Capybara_idle", true);

}

Capybara::~Capybara()
{

}

void Capybara::Update()
{
	GetAnimator()->Update();

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

void Capybara::Render(HDC _dc)
{
	Component_Render(_dc);
}
