#include "pch.h"
#include "Capybara.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "Collider.h"
#include "Texture.h"
#include "Core.h"

Capybara::Capybara()
	: texture{}
	, isDrag(false)
	, isStand(false)
	, isStage(false)
	, isAttatched(false)
	, dragStartPos{}
{
	texture[0] = ResMgr::GetInst()->TexLoad(L"Capybara", L"Texture\\CapybaraSheet.bmp");
	texture[1] = ResMgr::GetInst()->TexLoad(L"Stage", L"Texture\\stage.bmp");

	Vec2 vPos = GetPos();

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Capybara_idle", texture[0], Vec2(0.f, 0.f),
		Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 0.2f);
	GetAnimator()->CreateAnim(L"Capybara_Stand", texture[0], Vec2(512.f, 0.f), Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 1.f);

	CreateCollider();
	GetCollider()->SetScale(Vec2(512.f * 0.1f, 256.f * 0.2f));
	GetCollider()->SetOffSetPos(Vec2(vPos.x + 10, vPos.y + 20));

}

Capybara::~Capybara()
{

}

void Capybara::Update()
{
	if (isStage) {

	}
	else {
		if (!isStand) {
			GetAnimator()->PlayAnim(L"Capybara_idle", true);
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
	}
}

void Capybara::Render(HDC _dc)
{
	if (isStage) {
		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();
		Vec2 vScaleOffset = GetScaleOffset();
		int Width = texture[1]->GetWidth();
		int Height = texture[1]->GetHeight();

		HDC alphaDC = CreateCompatibleDC(_dc);
		HBITMAP alphabit = CreateCompatibleBitmap(_dc, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y);
		SelectObject(alphaDC, alphabit);

		PatBlt(alphaDC, 0, 0, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y, WHITENESS);

		StretchBlt(alphaDC
			, 0
			, 0
			, Width * vScaleOffset.x
			, Height * vScaleOffset.y
			, texture[1]->GetDC()
			, 0
			, 0
			, Width
			, Height
			, SRCCOPY);

		TransparentBlt(_dc
			, (int)(vPos.x - Height * vScaleOffset.x / 2.f)
			, (int)(vPos.y - Width * vScaleOffset.y / 2.f)
			, Width * vScaleOffset.x
			, Height * vScaleOffset.y
			, alphaDC
			, 0
			, 0
			, Width * vScaleOffset.x
			, Height * vScaleOffset.y
			, RGB(255, 0, 255));

		Component_Render(_dc);
		DeleteDC(alphaDC);
		DeleteObject(alphabit);
	}
	else
		Component_Render(_dc);
}

void Capybara::EnterCollision(Collider* _pOther)
{
	Capybara* obj = (Capybara*)_pOther->GetObj();
	
	Vec2 contactVec = obj->GetCollider()->GetFinalPos();
	Vec2 thisVec = GetCollider()->GetFinalPos();
	
	Vec2 calcVec = (thisVec - contactVec).Normalize();

	if (obj->GetIsStand()) {
		if (calcVec.y < -0.7f && !obj->GetIsAttatched()) {
			isStand = true;
			obj->SetIsAttatched(true);
		}
		else {
			return;
		}
	}
}

void Capybara::StayCollision(Collider* _pOther)
{
	if (isStage) return;
	GetAnimator()->PlayAnim(L"Capybara_Stand", true);
	if (isStand) {
		Core::GetInst()->isDragging = false;
		isDrag = false;
	}
}