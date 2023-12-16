#include "pch.h"
#include "MainScene.h"
#include "Core.h"
#include "MainBackground.h"
#include "SceneMgr.h"
#include "ExitButton.h"


void MainScene::Init()
{
	MainBackground* mainBackground = new MainBackground;

	ExitButton* exitButton = new ExitButton;
	exitButton->SetPos(Vec2(440, 45));
	exitButton->SetScale(Vec2(512.f * 0.1f, 512.f * 0.1f));
	exitButton->SetScaleOffset(Vec2(0.1f, 0.1f));

	POINT resolution = Core::GetInst()->GetResolution();
	float x = resolution.x / 1.33f;
	float y = resolution.y / 3.f;

	mainBackground->SetPos(Vec2(x, y));
	mainBackground->SetScale(Vec2(480, 720));
	mainBackground->SetScaleOffset(Vec2(1, 1));

	AddUI(exitButton, UI_GROUP::BUTTON);

	AddObject(mainBackground, OBJECT_GROUP::MAINBACKGROUND);
}

void MainScene::Update()
{
	Scene::Update();
}

void MainScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void MainScene::Release()
{
	Scene::Release();
}
