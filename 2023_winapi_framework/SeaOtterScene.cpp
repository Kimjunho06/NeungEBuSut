#include "pch.h"
#include "SeaOtterScene.h"
#include "Core.h"
#include "SeaOtter.h"
#include "Rock.h"
#include "Clam.h"
#include "StageBackground.h"
#include "StagePanel.h"
#include "GameTimeImage.h"
#include "EndTimeImage.h"
#include "ExitButton.h"


void SeaOtterScene::Init()
{
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

	SeaOtter* seaOtter = new SeaOtter;
	Rock* rock = new Rock;
	Clam* clam = new Clam;

	int x = resolution.x / 2;
	int y = resolution.y / 2 + 140;

	seaOtter->SetPos(Vec2(x - 50, y));
	seaOtter->SetScale(Vec2(512.f * 0.4f, 512.f * 0.4f));
	seaOtter->SetScaleOffset(Vec2(0.4f, 0.4f));
	
	rock->SetPos(Vec2(x + 70, y + 40));
	rock->SetScale(Vec2(512.f * 0.25f, 512.f * 0.25f));
	rock->SetScaleOffset(Vec2(0.25f, 0.25f));

	clam->SetPos(Vec2(x + 30, y - 80));
	clam->SetScale(Vec2(512.f * 0.2f, 512.f * 0.2f));
	clam->SetScaleOffset(Vec2(0.2f, 0.2f));

	AddObject(seaOtter, OBJECT_GROUP::SEAOTTER);
	AddObject(rock, OBJECT_GROUP::ROCK);
	AddObject(clam, OBJECT_GROUP::CLAM);

	AddUI(exitButton, UI_GROUP::BUTTON);
	AddUI(gametimeImage, UI_GROUP::IMAGE);
	AddUI(endtimeImage, UI_GROUP::IMAGE);
}

void SeaOtterScene::Update()
{
	Scene::Update();
}

void SeaOtterScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 4";
	wstring StageMissionText = L"화면을 클릭해 조개를 깨주세요";

	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2 - 188, vPos.y / 2 - 236, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2 - 174, vPos.y / 2 - 132, StageMissionText.c_str(), StageMissionText.length());
}

void SeaOtterScene::Release()
{
	Scene::Release();
}
