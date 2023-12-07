#include "pch.h"
#include "TurtleScene.h"
#include "SceneMgr.h"
#include "Turtle.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Flag.h"	
#include "TurtleButton.h"	
#include "Button.h"	

void TurtleScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	Object* turtle = new Turtle;
	Object* flag = new Flag;
	TurtleButton* clickBtn = new TurtleButton;

	float yOffset = 100.f;
	float x = 256 * 0.3f + 10;
	float y = resolution.y / 2;

	turtle->SetPos(Vec2({ x, y + yOffset }));
	turtle->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	turtle->SetScaleOffset({ 0.3f, 0.3f });

	flag->SetPos(Vec2(400.f, y + yOffset));
	flag->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	flag->SetScaleOffset({0.3f, 0.3f});

	clickBtn->SetPos(Vec2(resolution.x / 2.f, y + 270));
	clickBtn->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	clickBtn->SetScaleOffset(Vec2(0.3f, 0.3f));
	
	turtle->SetName(L"Turtle");
	flag->SetName(L"Flag");

	AddObject(turtle, OBJECT_GROUP::TURTLE);
	AddObject(flag, OBJECT_GROUP::FLAG);
	
	AddUI(clickBtn, UI_GROUP::BUTTON);

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
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());
	Vec2 vScale = Vec2(450, 620);
	RECT_RENDER(vPos.x / 2, vPos.y / 2 + 20, vScale.x, vScale.y, _dc);
	Scene::Render(_dc);
}

void TurtleScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
