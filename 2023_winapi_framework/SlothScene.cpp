#include "pch.h"
#include "SlothScene.h"
#include "Sloth.h"
#include "Core.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "Wood.h"
#include "StageBackground.h"
#include "StagePanel.h"
#include "GameTimeImage.h"
#include "EndTimeImage.h"
#include "ExitButton.h"
#include "ResMgr.h"


void SlothScene::Init()
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

	slothObj.clear();

	srand((unsigned int)time(NULL));
	Core::GetInst()->isDragging = false;

	int wx = resolution.x / 2;
	int wy = resolution.y / 2 + 100;

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

	AddObject(exitButton, OBJECT_GROUP::UI);
	AddObject(gametimeImage, OBJECT_GROUP::UI);
	AddObject(endtimeImage, OBJECT_GROUP::UI);

	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MAP, OBJECT_GROUP::SLOTH);
}

void SlothScene::Update()
{
	Scene::Update();
	for (auto obj : slothObj) {
		if (!obj->isHang) return;
	}

	SceneMgr::GetInst()->LoadScene(L"EndScene");
	Core::GetInst()->isGameClear = true;
	Core::GetInst()->isGameStart = false;
	if (Core::GetInst()->isGameClear > Core::GetInst()->gameTime) {
		Core::GetInst()->isGameClear = Core::GetInst()->gameTime;
	}
	ResMgr::GetInst()->Stop(SOUND_CHANNEL::BGM);
}

void SlothScene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	Vec2 vPos = Vec2(Core::GetInst()->GetResolution());

	wstring StageNumberText = L"STAGE 9"; // �������� ��ȣ �ؽ�Ʈ
	wstring StageMissionText = L"�巡�� �� ������ �Ŵ޾��ּ���"; // �������� �̼� �ؽ�Ʈ

	SetBkMode(_dc, 1); // �ؽ�Ʈ ��� ����ȭ

	TextOut(_dc, vPos.x / 2 - 188, vPos.y / 2 - 236, StageNumberText.c_str(), StageNumberText.length()); // �������� ��ȣ �ؽ�Ʈ ���
	TextOut(_dc, vPos.x / 2 - 178, vPos.y / 2 - 132, StageMissionText.c_str(), StageMissionText.length()); // �������� �̼� �ؽ�Ʈ ���

}

void SlothScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
