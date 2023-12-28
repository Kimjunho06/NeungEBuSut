#include "pch.h"
#include "EndScene.h"
#include "Core.h"
#include "MainButton.h"
#include "RestartButton.h"
#include "EndBackground.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

void EndScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	EndBackground* endBackground = new EndBackground;

	endBackground->SetPos(Vec2(resolution.x / 1.33f, resolution.y / 3.f));
	endBackground->SetScale(Vec2(480, 720));
	endBackground->SetScaleOffset(Vec2(1, 1));

	AddObject(endBackground, OBJECT_GROUP::ENDBACKGROUND);
}

void EndScene::Update()
{
	Scene::Update();

	if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
		SceneMgr::GetInst()->LoadScene(L"MainScene");
		Core::GetInst()->isGameStart = false;
		Core::GetInst()->gameTime = 0;
		Core::GetInst()->isGameClear = false;
		Core::GetInst()->isGameOver = false;
	}
}

void EndScene::Render(HDC _dc)
{
	Scene::Render(_dc);

	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring GameClearText = L"GameClear";
	wstring GameOverText = L"Game Over";
	wstring label = L"Tab To Menu!";

	SetBkMode(_dc, 1);

	if (Core::GetInst()->isGameClear)
		TextOut(_dc, vPos.x / 2-64, vPos.y / 2 -200, GameClearText.c_str(), GameClearText.length());
	if (Core::GetInst()->isGameOver)
		TextOut(_dc, vPos.x / 2 - 68, vPos.y / 2 - 200, GameOverText.c_str(), GameOverText.length());

	wstring time = L"Clear Time : " + Core::GetInst()->CalcTime(Core::GetInst()->gameTime);
	wstring recordtime = L"Record Time : " + Core::GetInst()->CalcTime(Core::GetInst()->gameTime);
	
	if (!Core::GetInst()->isGameOver) {
		TextOut(_dc, 120, 300, time.c_str(), time.size());
		TextOut(_dc, 120, 400, recordtime.c_str(), recordtime.size());
	}
	

	TextOut(_dc, vPos.x / 4 + 40, vPos.y - 100, label.c_str(), label.length());
}

void EndScene::Release()
{
	Scene::Release();
}
