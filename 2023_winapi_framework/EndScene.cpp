#include "pch.h"
#include "EndScene.h"
#include "Core.h"
#include "MainButton.h"
#include "RestartButton.h"
#include "EndBackground.h"

void EndScene::Init()
{
	POINT resolution = Core::GetInst()->GetResolution();

	EndBackground* endBackground = new EndBackground;

	endBackground->SetPos(Vec2(resolution.x / 1.33f, resolution.y / 3.f));
	endBackground->SetScale(Vec2(480, 720));
	endBackground->SetScaleOffset(Vec2(1, 1));

	AddObject(endBackground, OBJECT_GROUP::ENDBACKGROUND);

	int x = resolution.x / 2;
	int y = resolution.y / 2;

	MainButton* mainButton = new MainButton;
	RestartButton* restartButton = new RestartButton;

	mainButton->SetPos(Vec2(x-110, y+200));
	mainButton->SetScale(Vec2(300.f, 70.f));
	mainButton->SetScaleOffset(Vec2(1, 1));

	restartButton->SetPos(Vec2(x-110, y+300));
	restartButton->SetScale(Vec2(300.f, 70.f));
	restartButton->SetScaleOffset(Vec2(1, 1));

	AddUI(mainButton, UI_GROUP::BUTTON);
	AddUI(restartButton, UI_GROUP::BUTTON);
}

void EndScene::Update()
{
	Scene::Update();
}

void EndScene::Render(HDC _dc)
{
	Scene::Render(_dc);

	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring GameClearText = L"GameClear";
	wstring GameOverText = L"Game Over";

	SetBkMode(_dc, 1);

	TextOut(_dc, vPos.x / 2-64, vPos.y / 2 -200, GameClearText.c_str(), GameClearText.length());
	TextOut(_dc, vPos.x / 2 - 68, vPos.y / 2 - 200, GameOverText.c_str(), GameOverText.length());
}

void EndScene::Release()
{
	Scene::Release();
}
