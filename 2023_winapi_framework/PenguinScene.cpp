#include "pch.h"
#include "PenguinScene.h"
#include "Core.h"
#include "Penguin.h"
#include "SceneMgr.h"

void PenguinScene::Init()
{
	srand((unsigned int)time(NULL));

	POINT resolution = Core::GetInst()->GetResolution();

	penguinObj.clear();
	penguinCnt = 5;

	for (int i = 0; i < penguinCnt; i++) {
		Penguin* penguin = new Penguin;

		int x = resolution.x / 2;
		int y = resolution.y / 2;

		penguin->SetPos(Vec2(x + 200, y + 230 - (i * 60)));
		penguin->SetScale(Vec2(512.f * 0.2f, 512.f * 0.2f));
		penguin->SetScaleOffset(Vec2(0.2f, 0.2f));

		AddObject(penguin, OBJECT_GROUP::PENGUIN);
		penguinObj.push_back(penguin);
	}
}

void PenguinScene::Update()
{
	Scene::Update();

	for (auto obj : penguinObj) {
		if (!obj->isClick)
			return;
	}
	SceneMgr::GetInst()->LoadScene(L"Stage_1");
}

void PenguinScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void PenguinScene::Release()
{
	Scene::Release();
}
