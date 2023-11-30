#include "pch.h"
#include "SeaOtterScene.h"
#include "Core.h"
#include "SeaOtter.h"
#include "Rock.h"
#include "Clam.h"

void SeaOtterScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	SeaOtter* seaOtter = new SeaOtter;
	Rock* rock = new Rock;
	Clam* clam = new Clam;

	int x = resolution.x / 2;
	int y = resolution.y / 2;

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
}

void SeaOtterScene::Update()
{
	Scene::Update();
}

void SeaOtterScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void SeaOtterScene::Release()
{
	Scene::Release();
}
