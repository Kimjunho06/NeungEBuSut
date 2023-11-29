#include "pch.h"
#include "TurtleScene.h"
#include "SceneMgr.h"
#include "Turtle.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "Flag.h"	

void TurtleScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	Object* turtle = new Turtle;
	Object* flag = new Flag;

	float yOffset = 100.f;
	float x = 256 * 0.3f + 10;
	float y = resolution.y / 2;

	turtle->SetPos(Vec2({ x, y + yOffset }));
	turtle->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	turtle->SetScaleOffset({ 0.3f, 0.3f });

	flag->SetPos(Vec2(400.f, y + yOffset));
	flag->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
	flag->SetScaleOffset({0.3f, 0.3f});

	turtle->SetName(L"Turtle");
	flag->SetName(L"Flag");

	AddObject(turtle, OBJECT_GROUP::TURTLE);
	AddObject(flag, OBJECT_GROUP::FLAG);

	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::TURTLE, OBJECT_GROUP::FLAG);
}

void TurtleScene::Update()
{
	Scene::Update();

	//SceneMgr::GetInst()->LoadScene(L"Start_Scene");
}

void TurtleScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void TurtleScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
