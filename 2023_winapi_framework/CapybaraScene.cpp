#include "pch.h"
#include "CapybaraScene.h"
#include "Core.h"
#include "Capybara.h"
#include "StageBackground.h"
#include "CollisionMgr.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "StagePanel.h"

void CapybaraScene::Init()
{
	capybaraObj.clear();
	capybaraCnt = 5;

	Core::GetInst()->isDragging = false;

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

	Capybara* stage = new Capybara;

	Vec2 stagePos = Vec2(resolution.x / 2.f, resolution.y / 2.f + 300.f);

	stage->SetPos(Vec2(stagePos.x, stagePos.y - 10));
	stage->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	stage->SetScaleOffset(Vec2(0.3f, 0.3f));
	stage->SetIsStage(true);
	stage->SetIsStand(true);
	stage->GetCollider()->SetScale(Vec2(512.f * 0.05f, 256.f * 0.1f));
	stage->GetCollider()->SetOffSetPos(Vec2(0, -10));

	AddObject(stage, OBJECT_GROUP::CAPYBARA);
	capybaraObj.push_back(stage);
	
	for (int i = 0; i < capybaraCnt; i++) {
		Capybara* capybara = new Capybara;

		int x = rand() % 300 + 100;
		int y = rand() % 300 + 300;

		capybara->SetPos(Vec2(x, y));
		capybara->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
		capybara->SetScaleOffset(Vec2(0.3f, 0.3f));

		AddObject(capybara, OBJECT_GROUP::CAPYBARA);
		capybaraObj.push_back(capybara);
	}

	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::CAPYBARA, OBJECT_GROUP::CAPYBARA);
}

void CapybaraScene::Update()
{
	Scene::Update();

	for (auto obj : capybaraObj) {
		if (!obj->GetIsStand()) {
			return;
		}
	}


	SceneMgr::GetInst()->LoadScene(L"Stage_7");
}

void CapybaraScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 6";
	wstring StageMissionText = L"카피바라를 위로 쌓아주세요";
	
	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2 - 188, vPos.y / 2 - 236, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2 - 156, vPos.y / 2 - 132, StageMissionText.c_str(), StageMissionText.length());
}

void CapybaraScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
