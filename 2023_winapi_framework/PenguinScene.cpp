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

		penguin->SetPos(Vec2(x + 180, y + 230 - (i * 60)));
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
	SceneMgr::GetInst()->LoadScene(L"Stage_6");
}

void PenguinScene::Render(HDC _dc)
{
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());
	Vec2 vScale = Vec2(450, 620);
	RECT_RENDER(vPos.x / 2, vPos.y / 2 + 20, vScale.x, vScale.y, _dc);
	Scene::Render(_dc);
}

void PenguinScene::Release()
{
	Scene::Release();
}
