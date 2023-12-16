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
    // �ؽ�ó �޾ƿ���
    texture = ResMgr::GetInst()->TexLoad(L"Toucan.bmp", L"Texture\\Toucan.bmp");

    // �ִϸ��̼� ����
    CreateAnimator();
    GetAnimator()->CreateAnim(L"Toucan_CloseBeak", texture, Vec2(0.f, 0.f), Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 5.f);
    GetAnimator()->CreateAnim(L"Toucan_OpenBeak", texture, Vec2(512.f, 0.f), Vec2(512.f, 512.f), Vec2(512.f, 0.f), 1, 5.f);
}

Toucan::~Toucan()
{

}

void Toucan::Update()
{
    openTime += fDT; // ���� �󸶳� ���� ������ �־������� ����

    if (IsClickAble(this)) // Ŭ�� �ƴ°�
    {
        if (KEY_DOWN(KEY_TYPE::LBUTTON)) // ���� ���콺 ��ư���� Ŭ���ߴ°�
        {
            GetAnimator()->PlayAnim(L"Toucan_OpenBeak", false);
            isOpenBeak = true;
            openTime = 0;
        }
    }

    if (openTime >= 1.f) // 1�� �̻� ���� ������ �־��ٸ�
    {
        // ���� �ݾ��ش�
        GetAnimator()->PlayAnim(L"Toucan_CloseBeak", false);
        isOpenBeak = false;
    }
}

void Toucan::Render(HDC _dc)
{
    Component_Render(_dc);
}