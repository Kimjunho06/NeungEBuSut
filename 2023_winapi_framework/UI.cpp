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

bool UI::IsClickAble(UI* ui)
{
	POINT mousePos = KeyMgr::GetInst()->GetMousePos();
	int left = ui->m_vPos.x - ui->m_vScale.x / 2;
	int right = ui->m_vPos.x + ui->m_vScale.x / 2;
	int top = ui->m_vPos.y - ui->m_vScale.y / 2;
	int bottom = ui->m_vPos.y + ui->m_vScale.y / 2;

	if (mousePos.x < left || mousePos.x > right) return false;
	if (mousePos.y < top || mousePos.y > bottom) return false;

	return true;
}
