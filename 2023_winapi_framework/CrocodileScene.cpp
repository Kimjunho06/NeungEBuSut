#include "pch.h"
#include "CrocodileScene.h"
#include "CollisionMgr.h"
#include "Crocodile.h"
#include "Fish.h"
#include "Core.h"

void CrocodileScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	Crocodile* crocodile = new Crocodile;
	Fish* fish = new Fish;

	int x = resolution.x / 2;
	int y = resolution.y / 2;

	crocodile->SetPos(Vec2(x, y));
	crocodile->SetScale(Vec2(512.f * 0.4f, 512.f * 0.4f));
	crocodile->SetScaleOffset(Vec2(0.4f, 0.4f));
	crocodile->SetName(L"Crocodile");

	fish->SetPos(Vec2(x - 200, y + 110));
	fish->SetScale(Vec2(512.f * 0.2f, 512.f * 0.2f));
	fish->SetScaleOffset(Vec2(0.2f, 0.2f));
	fish->SetName(L"Fish");


	AddObject(crocodile, OBJECT_GROUP::CROCODILE);
	AddObject(fish, OBJECT_GROUP::FISH);


	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::FISH, OBJECT_GROUP::CROCODILE);

}

void CrocodileScene::Update()
{
	Scene::Update();
}

void CrocodileScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void CrocodileScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}