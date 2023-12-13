#include "pch.h"
#include "ToucanScene.h"
#include "Core.h"
#include "Toucan.h"
#include "Wood.h"
#include "SceneMgr.h"

void ToucanScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	for (int i = 0; i < 3; i++)
	{
		Toucan* toucan = new Toucan;

		int xOffset = resolution.x / 2;
		int yOffset = resolution.y / 6;
		int x = resolution.x / 4 + 30;
		int y = resolution.y / 2;

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
	int wy = resolution.y / 2;

	wood->SetPos(Vec2(wx / 2, wy + 280));
	wood->SetScale(Vec2(512.f, 512.f));
	wood->SetScaleOffset(Vec2(1, 1));
	AddObject(wood, OBJECT_GROUP::MAP);
}

void ToucanScene::Update()
{
	Scene::Update();

	totalOpenToucan = 0;

	for (int i = 0; i < toucans.size(); i++)
	{
		if (toucans[i]->isOpenBeak)
		{
			totalOpenToucan++;
		}
	}

	if (totalToucan == totalOpenToucan)
	{
		SceneMgr::GetInst()->LoadScene(L"Stage_8");
	}
}

void ToucanScene::Render(HDC _dc)
{
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());
	Vec2 vScale = Vec2(450, 620);
	RECT_RENDER(vPos.x / 2, vPos.y / 2 + 20, vScale.x, vScale.y, _dc);
	Scene::Render(_dc);
}

void ToucanScene::Release()
{
	Scene::Release();
}