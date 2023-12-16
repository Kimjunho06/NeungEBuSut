#include "pch.h"
#include "ChameleonScene.h"
#include "SceneMgr.h"
#include "Chameleon.h"
#include "ColorObject.h"
#include "Core.h"
#include "Wood.h"
#include "StageBackground.h"
#include "StagePanel.h"
#include "GameTimeImage.h"
#include "EndTimeImage.h"
#include "ExitButton.h"

void ChameleonScene::Init()
{
	srand((unsigned int)time(NULL));
	chameleonObj.clear();
	chameleonColorObj.clear();

	chameleonCnt = 3;
	POINT resolution = Core::GetInst()->GetResolution();

	ExitButton* exitButton = new ExitButton;
	exitButton->SetPos(Vec2(440, 45));
	exitButton->SetScale(Vec2(512.f * 0.1f, 512.f * 0.1f));
	exitButton->SetScaleOffset(Vec2(0.1f, 0.1f));

	StageBackground* stageBackground = new StageBackground;
	GameTimeImage* gametimeImage = new GameTimeImage;
	EndTimeImage* endtimeImage = new EndTimeImage;

	gametimeImage->SetPos(Vec2(50, 45));
	gametimeImage->SetScale(Vec2(594.f * 0.08f, 598.f * 0.08f));
	gametimeImage->SetScaleOffset(Vec2(0.08f, 0.08f));
	
	endtimeImage->SetPos(Vec2(180, 45));
	endtimeImage->SetScale(Vec2(594.f * 0.08f, 598.f * 0.08f));
	endtimeImage->SetScaleOffset(Vec2(0.08f, 0.08f));


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


	for (int i = 0; i < chameleonCnt; i++) {
		Chameleon* chameleon = new Chameleon;
		ColorObject* chameleonColor = new ColorObject;

		int xOffset = resolution.x / 2;
		int yOffset = resolution.y / 6;
		int x = resolution.x / 4 + 15;
		int y = resolution.y / 2 + 60;
		
		Vec2 vColorPos = Vec2({ xOffset + x * (i-1), y - yOffset + 70});
		Vec2 vColorScale = Vec2(512.f * 0.2f, 512.f * 0.2f);
		Vec2 vColorScaleOffset = Vec2(0.2f, 0.2f);

		Vec2 vPos = Vec2({ xOffset + x * (i-1), y - 20 + 100});
		Vec2 vScale = Vec2(512.f * 0.25f, 512.f * 0.25f);
		Vec2 vScaleOffset = Vec2(0.25f, 0.25f);

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

	for (int i = 0; i < chameleonCnt; i++) {
		if (chameleonObj[i]->GetColorIdx() == chameleonColorObj[i]->GetColorIdx()) {
			matchCnt++;
		}
	}
	if (matchCnt == chameleonObj.size()) {
		int idx = chameleonObj[chameleonObj.size() - 1]->GetColorIdx();
		switch (idx)
		{
			case 0:
				chameleonObj[chameleonObj.size() - 1]->SetColorIdx(1);
				break;
			case 1:
				chameleonObj[chameleonObj.size() - 1]->SetColorIdx(2);
				break;
			case 2:
				chameleonObj[chameleonObj.size() - 1]->SetColorIdx(0);
				break;
		}
	}

	Wood* wood = new Wood;
	int yOffset = 20;
	
	int wx = resolution.x / 2;
	int wy = resolution.y / 2 + 60;

	wood->SetPos(Vec2(wx / 2+4, wy + 250));
	wood->SetScale(Vec2(512.f, 512.f));
	wood->SetScaleOffset(Vec2(0.98f, 1.f)); 
	AddObject(wood, OBJECT_GROUP::MAP);

	matchCnt = 0;
	clearCnt = chameleonObj.size();
	AddObject(exitButton, OBJECT_GROUP::UI);
	AddObject(gametimeImage, OBJECT_GROUP::UI);
	AddObject(endtimeImage, OBJECT_GROUP::UI);
}

void ChameleonScene::Update()
{
	Scene::Update();

	// 카멜레온 색 바뀌는 거
	matchCnt = 0;
	for (int i = 0; i < chameleonCnt; i++) {
		if (chameleonObj[i]->GetColorIdx() == chameleonColorObj[i]->GetColorIdx()) 
		{
			matchCnt++;
		}
	}

	if (matchCnt == clearCnt && !Core::GetInst()->isExitOnButton)
	{
		SceneMgr::GetInst()->LoadScene(L"Stage_2");
	}
}

void ChameleonScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 1"; 
	wstring StageMissionText = L"클릭해 색을 바꿔주세요";

	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2-188, vPos.y / 2-236, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2-134, vPos.y / 2-132, StageMissionText.c_str(), StageMissionText.length());
}

void ChameleonScene::Release()
{
	Scene::Release();
}
