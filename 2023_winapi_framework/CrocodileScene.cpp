#include "pch.h"
#include "CrocodileScene.h"
#include "CollisionMgr.h"
#include "Crocodile.h"
#include "Fish.h"
#include "Core.h"
#include "StageBackground.h"
#include "StagePanel.h"
#include "GameTimeImage.h"
#include "EndTimeImage.h"
#include "ExitButton.h"


void CrocodileScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	float sx = resolution.x / 1.33f;
	float sy = resolution.y / 3.f;

	Vec2 vPos = Vec2(sx, sy);
	Vec2 vScale = Vec2(480, 720);

	ExitButton* exitButton = new ExitButton;
	exitButton->SetPos(Vec2(440, 45));
	exitButton->SetScale(Vec2(512.f * 0.1f, 512.f * 0.1f));
	exitButton->SetScaleOffset(Vec2(0.1f, 0.1f));

	StageBackground* stageBackground = new StageBackground;
	Crocodile* crocodile = new Crocodile;
	Fish* fish = new Fish;

	int x = resolution.x / 2;
	int y = resolution.y / 2;

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

	StagePanel* stagePanel = new StagePanel;

	float px = resolution.x / 1.5f;
	float py = resolution.y / 2.25f;

	stagePanel->SetPos(Vec2(px, py));
	stagePanel->SetScale(Vec2(448, 608));
	stagePanel->SetScaleOffset(Vec2(1, 1));

	AddObject(stagePanel, OBJECT_GROUP::STAGEPANEL);

	crocodile->SetPos(Vec2(x, y + 42));
	crocodile->SetScale(Vec2(512.f * 0.4f, 512.f * 0.4f));
	crocodile->SetScaleOffset(Vec2(0.4f, 0.4f));
	crocodile->SetName(L"Crocodile");

	fish->SetPos(Vec2(x - 200, y + 160));
	fish->SetScale(Vec2(512.f * 0.2f, 512.f * 0.2f));
	fish->SetScaleOffset(Vec2(0.2f, 0.2f));
	fish->SetName(L"Fish");


	AddObject(stageBackground, OBJECT_GROUP::STAGEBACKGROUND);
	AddObject(crocodile, OBJECT_GROUP::CROCODILE);
	AddObject(fish, OBJECT_GROUP::FISH);

	AddObject(exitButton, OBJECT_GROUP::UI);
	AddObject(gametimeImage, OBJECT_GROUP::UI);
	AddObject(endtimeImage, OBJECT_GROUP::UI);

	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::FISH, OBJECT_GROUP::CROCODILE);

}

void CrocodileScene::Update()
{
	Scene::Update();
}

void CrocodileScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 3";
	wstring StageMissionText = L"화면을 클릭해 물고기를 먹여주세요";

	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2 - 188, vPos.y / 2 - 236, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2 - 194, vPos.y / 2 - 132, StageMissionText.c_str(), StageMissionText.length());

}

void CrocodileScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}