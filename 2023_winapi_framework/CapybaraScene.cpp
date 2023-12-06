#include "pch.h"
#include "CapybaraScene.h"
#include "Core.h"
#include "Capybara.h"
#include "CollisionMgr.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

void CapybaraScene::Init()
{
	capybaraObj.clear();
	capybaraCnt = 5;

	Core::GetInst()->isDragging = false;

	srand((unsigned int)time(NULL));
	POINT resolution = Core::GetInst()->GetResolution();

	Capybara* stage = new Capybara;

	Vec2 stagePos = Vec2(resolution.x / 2.f, resolution.y / 2.f + 300.f);

	stage->SetPos(Vec2(stagePos.x, stagePos.y));
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

		int x = rand() % 400 + 40;
		int y = rand() % 500 + 200;

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


	SceneMgr::GetInst()->LoadScene(L"Stage_1");
}

void CapybaraScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void CapybaraScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
