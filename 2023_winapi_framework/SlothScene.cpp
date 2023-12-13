#include "pch.h"
#include "SlothScene.h"
#include "Sloth.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "Wood.h"

void SlothScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	slothObj.clear();

	srand((unsigned int)time(NULL));
	Core::GetInst()->isDragging = false;

	int wx = resolution.x / 2;
	int wy = resolution.y / 2;

	slothCnt = 4;

	Wood* wood = new Wood();

	wood->SetPos(Vec2(wx / 2, wy + 100));
	wood->SetScale(Vec2(512.f, 512.f));
	wood->SetScaleOffset(Vec2(1, 1));
	wood->SetName(L"Wood");
	wood->isSlothWood = true;

	AddObject(wood, OBJECT_GROUP::MAP);

	for (int i = 0; i < slothCnt; i++) {
		Sloth* sloth = new Sloth;
		
		int x = rand() % 300 + 100;
		int y = rand() % 300 + 400;

		sloth->SetPos(Vec2(x, y));
		sloth->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
		sloth->SetScaleOffset(Vec2(0.3f, 0.3f));

		AddObject(sloth, OBJECT_GROUP::SLOTH);
		slothObj.push_back(sloth);
	}

	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MAP, OBJECT_GROUP::SLOTH);
}

void SlothScene::Update()
{
	Scene::Update();
	for (auto obj : slothObj) {
		if (!obj->isHang) return;
	}

	SceneMgr::GetInst()->LoadScene(L"Stage_1");
}

void SlothScene::Render(HDC _dc)
{
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());
	Vec2 vScale = Vec2(450, 620);
	RECT_RENDER(vPos.x / 2, vPos.y / 2 + 20, vScale.x, vScale.y, _dc);
	Scene::Render(_dc);
}

void SlothScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
