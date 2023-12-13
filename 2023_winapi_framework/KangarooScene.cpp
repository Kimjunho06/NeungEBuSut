#include "pch.h"
#include "KangarooScene.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Kangaroo.h"
#include "Rock.h"
#include "Ground.h"
#include "Flag.h"

void KangarooScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	rockObj.clear();

	Ground* ground = new Ground;
	Kangaroo* kangaroo = new Kangaroo;
	Flag* flag = new Flag;

	float x = resolution.x / 2;
	float y = resolution.y / 2;

	ground->SetPos(Vec2({ x, y + 290 }));
	ground->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	ground->SetScaleOffset({ 0.3f, 0.3f });
	ground->SetName(L"Ground");

	kangaroo->SetPos(Vec2({ x, y + 200}));
	kangaroo->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	kangaroo->SetScaleOffset({ 0.3f, 0.3f });
	kangaroo->SetName(L"Kangaroo");

	flag->SetPos(Vec2({ x + 3000, y + 180}));
	flag->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	flag->SetScaleOffset({ 0.3f, 0.3f });
	flag->SetName(L"Flag");
	flag->isKangarooFlag = true;

	AddObject(kangaroo, OBJECT_GROUP::KANGAROO);
	AddObject(ground, OBJECT_GROUP::MAP);
	AddObject(flag, OBJECT_GROUP::FLAG);

	for (int i = 0; i < 5; i++) {
		Rock* rock = new Rock;

		rock->SetPos(Vec2({ x + ((i + 1) * 500), y + 220}));
		rock->SetScale(Vec2(512.f * 0.2f, 512.f * 0.2f));
		rock->SetScaleOffset({ 0.2f, 0.2f });
		rock->SetName(L"Rock");
		rock->isKangarooRock = true;

		rockObj.push_back(rock);

		AddObject(rock, OBJECT_GROUP::ROCK);
	}

	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MAP, OBJECT_GROUP::KANGAROO);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::ROCK, OBJECT_GROUP::KANGAROO);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::FLAG, OBJECT_GROUP::KANGAROO);
}

void KangarooScene::Update()
{
	Object* kangarooObj = GetGroupObject(OBJECT_GROUP::KANGAROO)[0];
	Object* flagObj = GetGroupObject(OBJECT_GROUP::FLAG)[0];

	Kangaroo* kangaroo = (Kangaroo*)kangarooObj;
	Flag* flag = (Flag*)flagObj;
	POINT resolution = Core::GetInst()->GetResolution();

	float x = resolution.x / 2;
	float y = resolution.y / 2;

	if (kangaroo->isDie) {
		kangaroo->isfall = true;
		kangaroo->isDie = false;

		for (int i = 0; i < 5; i++) {
			rockObj[i]->SetPos(Vec2({ x + ((i + 1) * 500), y + 220 }));
		}
		flag->SetPos(Vec2({ x + 3000, y + 180 }));
	}
	Scene::Update();
}

void KangarooScene::Render(HDC _dc)
{
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());
	Vec2 vScale = Vec2(450, 620);
	RECT_RENDER(vPos.x / 2, vPos.y / 2 + 20, vScale.x, vScale.y, _dc);
	Scene::Render(_dc);
}

void KangarooScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}