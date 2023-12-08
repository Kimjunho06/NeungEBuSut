#include "pch.h"
#include "CapybaraScene.h"
#include "Core.h"
#include "Capybara.h"
#include "KeyMgr.h"

void CapybaraScene::Init()
{
	capybaraObj.clear();
	capybaraCnt = 5;
	Core::GetInst()->isDragging = false;

	srand((unsigned int)time(NULL));
	POINT resolution = Core::GetInst()->GetResolution();

	for (int i = 0; i < capybaraCnt; i++) {
		Capybara* capybara = new Capybara;

		int x = rand() % 400 + 40;
		int y = rand() % 500 + 200;

		capybara->SetPos(Vec2(x, y));
		capybara->SetScale(Vec2(512.f * 0.3f, 512.f * 0.3f));
		capybara->SetScaleOffset(Vec2(0.3f, 0.3f));

		AddObject(capybara, OBJECT_GROUP::CAPYBARA);
		capybaraObj.push_back(capybara);
	}
}

void CapybaraScene::Update()
{
	Scene::Update();
}

void CapybaraScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void CapybaraScene::Release()
{
	Scene::Release();
}
