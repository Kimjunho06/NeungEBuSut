#include "pch.h"
#include "PenguinScene.h"
#include "Core.h"
#include "Penguin.h"
#include "SceneMgr.h"
#include "StageBackground.h"
#include "StagePanel.h"
#include "GameTimeImage.h"
#include "EndTimeImage.h"
#include "ExitButton.h"


void PenguinScene::Init()
{
	srand((unsigned int)time(NULL));

	POINT resolution = Core::GetInst()->GetResolution();

	StageBackground* stageBackground = new StageBackground;

	ExitButton* exitButton = new ExitButton;
	exitButton->SetPos(Vec2(440, 45));
	exitButton->SetScale(Vec2(512.f * 0.1f, 512.f * 0.1f));
	exitButton->SetScaleOffset(Vec2(0.1f, 0.1f));

	float sx = resolution.x / 1.33f;
	float sy = resolution.y / 3.f;

	Vec2 vPos = Vec2(sx, sy);
	Vec2 vScale = Vec2(480, 720);

	GameTimeImage* gametimeImage = new GameTimeImage;
	EndTimeImage* endtimeImage = new EndTimeImage;

	gametimeImage->SetPos(Vec2(50, 45));
	gametimeImage->SetScale(Vec2(594.f * 0.08f, 598.f * 0.08f));
	gametimeImage->SetScaleOffset(Vec2(0.08f, 0.08f));

	endtimeImage->SetPos(Vec2(180, 45));
	endtimeImage->SetScale(Vec2(594.f * 0.08f, 598.f * 0.08f));
	endtimeImage->SetScaleOffset(Vec2(0.08f, 0.08f));

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


	AddObject(exitButton, OBJECT_GROUP::UI);
	AddObject(gametimeImage, OBJECT_GROUP::UI);
	AddObject(endtimeImage, OBJECT_GROUP::UI);

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

	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2 - 188, vPos.y / 2 - 236, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2 - 138, vPos.y / 2 - 132, StageMissionText.c_str(), StageMissionText.length());

}

void PenguinScene::Release()
{
	Scene::Release();
}
