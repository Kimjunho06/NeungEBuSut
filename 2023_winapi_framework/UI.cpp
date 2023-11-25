#include "pch.h"
#include "KeyMgr.h"
#include "UI.h"

UI::UI()
	: isEnable(false)
	, m_vPos{}
	, m_vScale{}
{
}

UI::~UI()
{

}

bool UI::IsClickAble()
{
	POINT mousePos = KeyMgr::GetInst()->GetMousePos();
	int left = m_vPos.x - m_vScale.x / 2;
	int right = m_vPos.x + m_vScale.x / 2;
	int top = m_vPos.y - m_vScale.y / 2;
	int bottom = m_vPos.y + m_vScale.y / 2;

	if (mousePos.x < left || mousePos.x > right) return false;
	if (mousePos.y < top || mousePos.y > bottom) return false;

	return true;
}
