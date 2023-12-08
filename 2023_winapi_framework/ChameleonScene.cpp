#include "pch.h"
#include "ChameleonScene.h"
#include "SceneMgr.h"
#include "Chameleon.h"
#include "ColorObject.h"
#include "Core.h"
#include "Wood.h"

void ChameleonScene::Init()
{
	srand((unsigned int)time(NULL));
	chameleonObj.clear();
	chameleonColorObj.clear();

	chameleonCnt = 3;
	POINT resolution = Core::GetInst()->GetResolution();
	for (int i = 0; i < chameleonCnt; i++) {
		Chameleon* chameleon = new Chameleon;
		ColorObject* chameleonColor = new ColorObject;

		int xOffset = resolution.x / 2;
		int yOffset = resolution.y / 6;
		int x = resolution.x / 4 + 30;
		int y = resolution.y / 2;
		
		Vec2 vColorPos = Vec2({ xOffset + x * (i-1), y - yOffset + 70});
		Vec2 vColorScale = Vec2(512.f * 0.2f, 512.f * 0.2f);
		Vec2 vColorScaleOffset = Vec2(0.2f, 0.2f);

		Vec2 vPos = Vec2({ xOffset + x * (i-1), y - 20 + 100});
		Vec2 vScale = Vec2(512.f * 0.3f, 512.f * 0.3f);
		Vec2 vScaleOffset = Vec2(0.3f, 0.3f);

		chameleon->SetPos(vPos);
		chameleon->SetScale(vScale);
		chameleon->SetScaleOffset(vScaleOffset);

		chameleonColor->SetPos(vColorPos);
		chameleonColor->SetScale(vColorScale);
		chameleonColor->SetScaleOffset(vColorScaleOffset);

		AddObject(chameleon, OBJECT_GROUP::CHAMELEON);
		AddObject(chameleonColor, OBJECT_GROUP::CHAMELEONCOLOR);
		chameleonObj.push_back(chameleon);
		chameleonColorObj.push_back(chameleonColor);
	}
	Wood* wood = new Wood;
	int yOffset = 20;
	Vec2 vPos = Vec2({ resolution.x / 2, resolution.y / 2 + yOffset *2 + 100 });
	Vec2 vScale = Vec2({ 448, 212 });
	Vec2 vScaleOffset = Vec2(1.f, 1.f);
	wood->SetPos(vPos); // 2048 512
	wood->SetScale(vScale);
	wood->SetScaleOffset(vScaleOffset);
	AddObject(wood, OBJECT_GROUP::MAP);

	matchCnt = 0;
	clearCnt = chameleonObj.size();
}

void ChameleonScene::Update()
{
	Scene::Update();

	// Ä«¸á·¹¿Â »ö ¹Ù²î´Â °Å
	matchCnt = 0;
	for (int i = 0; i < chameleonCnt; i++) {
		if (chameleonObj[i]->GetColorIdx() == chameleonColorObj[i]->GetColorIdx()) 
		{
			matchCnt++;
		}
	}

	if (matchCnt == clearCnt) {
		SceneMgr::GetInst()->LoadScene(L"Stage_2");
	}
}

void ChameleonScene::Render(HDC _dc)
{
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());
	Vec2 vScale = Vec2(450, 620);
	RECT_RENDER(vPos.x / 2, vPos.y / 2 + 20, vScale.x, vScale.y, _dc);
	Scene::Render(_dc);
	
}

void ChameleonScene::Release()
{
	Scene::Release();
}
