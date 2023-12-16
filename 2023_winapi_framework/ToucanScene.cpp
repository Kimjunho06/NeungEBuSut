#include "pch.h"
#include "ToucanScene.h"
#include "Core.h"
#include "Toucan.h"
#include "Wood.h"
#include "StageBackground.h"
#include "StagePanel.h"
#include "SceneMgr.h"

void ToucanScene::Init()
{
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

	for (int i = 0; i < 3; i++)
	{
		Toucan* toucan = new Toucan;

		int xOffset = resolution.x / 2;
		int yOffset = resolution.y / 6;
		int x = resolution.x / 4 + 15;
		int y = resolution.y / 2 + 60;

		Vec2 vPos = Vec2({ xOffset + x * (i - 1), y - 20 + 100 });
		Vec2 vScale = Vec2(512.f * 0.3f, 512.f * 0.3f);
		Vec2 vScaleOffset = Vec2(0.3f, 0.3f);

		toucan->SetPos(vPos);
		toucan->SetScale(vScale);
		toucan->SetScaleOffset(vScaleOffset);

		AddObject(toucan, OBJECT_GROUP::TOUCAN);
		toucans.push_back(toucan);
	}

	totalToucan = toucans.size();
	totalOpenToucan = 0;

	Wood* wood = new Wood;
	int yOffset = 20;
	
	int wx = resolution.x / 2;
	int wy = resolution.y / 2 + 90;

	wood->SetPos(Vec2(wx / 2 + 4, wy + 250));
	wood->SetScale(Vec2(512.f, 512.f));
	wood->SetScaleOffset(Vec2(0.98f, 1.f));
	AddObject(wood, OBJECT_GROUP::MAP);
}

void ToucanScene::Update()
{
	Scene::Update();

	totalOpenToucan = 0; // 현재 부리를 벌리고 있는 큰 부리 새의 수

	for (int i = 0; i < toucans.size(); i++)  // 모든 큰 부리새를 확인
	{
		if (toucans[i]->isOpenBeak) // 현재 큰 부리새는 입을 벌리고 있는지 체크
		{
			totalOpenToucan++; // 입을 벌린 큰 부리새 수 추가
		}
	}

	if (totalToucan == totalOpenToucan) // 현재 총 큰 부리새의 수와 입을 벌린 큰 부리새 수가 같은지 확인
	{
		SceneMgr::GetInst()->LoadScene(L"Stage_8"); // 같다면 클리어되어 다음 씬으로
	}
}

void ToucanScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 7";
	wstring StageMissionText = L"클릭해 부리를 벌려주세요";

	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2 - 200, vPos.y / 2 - 242, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2 - 175, vPos.y / 2 - 135, StageMissionText.c_str(), StageMissionText.length());

}

void ToucanScene::Release()
{
	Scene::Release();
}