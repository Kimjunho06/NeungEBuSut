#include "pch.h"
#include "Toucan.h"
#include "ResMgr.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Animator.h"
#include "Animation.h"

Toucan::Toucan() : texture(nullptr), isOpenBeak(false), openTime(1.f)
{
    // 텍스처 받아오기
    texture = ResMgr::GetInst()->TexLoad(L"Toucan.bmp", L"Texture\\Toucan.bmp");

    // 애니메이션 세팅
    CreateAnimator();
    GetAnimator()->CreateAnim(L"Toucan_CloseBeak", texture, Vec2(0.f, 0.f), Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 5.f);
    GetAnimator()->CreateAnim(L"Toucan_OpenBeak", texture, Vec2(512.f, 0.f), Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 5.f);
}

Toucan::~Toucan()
{

}

void Toucan::Update()
{
    openTime += fDT; // 현재 얼마나 입을 벌리고 있었는지를 저장

    if (IsClickAble(this)) // 클릭 됐는가
    {
        if (KEY_DOWN(KEY_TYPE::LBUTTON)) // 좌측 마우스 버튼으로 클릭했는가
        {
            GetAnimator()->PlayAnim(L"Toucan_OpenBeak", false);
            isOpenBeak = true;
            openTime = 0;
        }
    }

    if (openTime >= 1.f) // 1초 이상 입을 벌리고 있었다면
    {
        // 입을 닫아준다
        GetAnimator()->PlayAnim(L"Toucan_CloseBeak", false);
        isOpenBeak = false;
    }
}

void Toucan::Render(HDC _dc)
{
    Component_Render(_dc);
}