#include "pch.h"
#include "PenguinScene.h"
#include "Core.h"
#include "Penguin.h"
#include "SceneMgr.h"
#include "StageBackground.h"
#include "StagePanel.h"

void PenguinScene::Init()
{
	srand((unsigned int)time(NULL));

	POINT resolution = Core::GetInst()->GetResolution();

	StageBackground* stageBackground = new StageBackground;

	float sx = resolution.x / 1.33f;
	float sy = resolution.y / 3.f;

	Vec2 vPos = Vec2(sx, sy);
	Vec2 vScale = Vec2(480, 720);

	stageBackground->SetPos(vPos);
	stageBackground->SetScale(vScale);
	stageBackground->SetScaleOffset(Vec2(1, 1));

	AddObject(stageBackground, OBJECT_GROUP::STAGEBACKGROUND);

	StagePanel* stagePanel = new StagePanel;

	float px = resolution.x / 1.5f;
	float py = resolution.y / 2.25f;

	stagePanel->SetPos(Vec2(px, py));
	stagePanel->SetScale(Vec2(448, 608));
	stagePanel->SetScaleOffset(Vec2(1, 1));

	AddObject(stagePanel, OBJECT_GROUP::STAGEPANEL);

	penguinObj.clear();
	penguinCnt = 5;

	for (int i = 0; i < penguinCnt; i++) {
		Penguin* penguin = new Penguin;

		int x = resolution.x / 2;
		int y = resolution.y / 2 + 35;

		penguin->SetPos(Vec2(x + 180, y + 230 - (i * 60)));
		penguin->SetScale(Vec2(512.f * 0.2f, 512.f * 0.2f));
		penguin->SetScaleOffset(Vec2(0.2f, 0.2f));

		AddObject(penguin, OBJECT_GROUP::PENGUIN);
		penguinObj.push_back(penguin);
	}
}

void PenguinScene::Update()
{
	Scene::Update();

	for (auto obj : penguinObj) {
		if (!obj->isClick)
			return;
	}
	SceneMgr::GetInst()->LoadScene(L"Stage_6");
}

void PenguinScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 5";
	wstring StageMissionText = L"∆Î±œ¿ª ≈¨∏Ø«ÿ ∏ÿ√Á¡÷ººø‰";

	TextOut(_dc, vPos.x / 2, vPos.y / 2, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2, vPos.y / 2, StageMissionText.c_str(), StageMissionText.length());

}

void PenguinScene::Release()
{
	Scene::Release();
}
