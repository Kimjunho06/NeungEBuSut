#include "pch.h"
#include "TurtleScene.h"
#include "SceneMgr.h"
#include "Turtle.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Flag.h"	
#include "TurtleButton.h"	
#include "StageBackground.h"
#include "StagePanel.h"
#include "Button.h"	
#include "GameTimeImage.h"
#include "EndTimeImage.h"
#include "ExitButton.h"


void TurtleScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	StageBackground* stageBackground = new StageBackground;

	ExitButton* exitButton = new ExitButton;
	exitButton->SetPos(Vec2(440, 45));
	exitButton->SetScale(Vec2(512.f * 0.1f, 512.f * 0.1f));
	exitButton->SetScaleOffset(Vec2(0.1f, 0.1f));

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

	Object* turtle = new Turtle;
	Object* flag = new Flag;
	TurtleButton* clickBtn = new TurtleButton;

	float yOffset = 100.f;
	float x = 256 * 0.3f + 10;
	float y = resolution.y / 2;

	turtle->SetPos(Vec2({ x + 25, y + yOffset }));
	turtle->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	turtle->SetScaleOffset({ 0.3f, 0.3f });

	flag->SetPos(Vec2(375.f, y + yOffset));
	flag->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	flag->SetScaleOffset({0.3f, 0.3f});

	clickBtn->SetPos(Vec2(resolution.x / 4.f, resolution.y / 2.f + 370));
	clickBtn->SetScale(Vec2(512.f, 512.f));
	clickBtn->SetScaleOffset(Vec2(1.f, 1.f));
	
	turtle->SetName(L"Turtle");
	flag->SetName(L"Flag");

	AddObject(turtle, OBJECT_GROUP::TURTLE);
	AddObject(flag, OBJECT_GROUP::FLAG);
	AddUI(clickBtn, UI_GROUP::BUTTON);
	AddUI(exitButton, UI_GROUP::IMAGE);
	AddUI(gametimeImage, UI_GROUP::IMAGE);
	AddUI(endtimeImage, UI_GROUP::IMAGE);

	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::TURTLE, OBJECT_GROUP::FLAG);
}

void TurtleScene::Update()
{
	Scene::Update();

	UI* buttonObj = GetGroupUI(UI_GROUP::BUTTON)[0];
	Object* turtleObj = GetGroupObject(OBJECT_GROUP::TURTLE)[0];
	
	Turtle* turtle = (Turtle*)turtleObj;
	TurtleButton* turtleBtn = (TurtleButton*)buttonObj;

	//Vec2 vPos = turtle->GetPos();
	//vPos.x += turtleBtn->GetSpeed();

	//turtle->SetPos(vPos);

	turtle->SetSpeed(turtleBtn->GetSpeed());
}

void TurtleScene::Render(HDC _dc)
{
	Scene::Render(_dc);

	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 2";
	wstring StageMissionText = L"버튼을 눌러 이동시켜주세요";

	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2 - 188, vPos.y / 2 - 236, StageNumberText.c_str(), StageNumberText.length());
	TextOut(_dc, vPos.x / 2 - 154, vPos.y / 2 - 132, StageMissionText.c_str(), StageMissionText.length());

}

void TurtleScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
