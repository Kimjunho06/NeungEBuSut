#include "pch.h"
#include "SceneMgr.h"
#include "UIMgr.h"
#include "Start_Scene.h"
#include "Game_Scene.h"
#include "ChameleonScene.h"
#include "TurtleScene.h"
#include "CrocodileScene.h"
#include "SeaOtterScene.h"
#include "PenguinScene.h"
#include "CapybaraScene.h"
#include "KangarooScene.h"
#include "ToucanScene.h"
#include "SlothScene.h"

void SceneMgr::Init()
{
	m_pCurScene = nullptr;
	// ¾À µî·Ï
	RegisterScene(L"Start_Scene",std::make_shared<Start_Scene>());
	RegisterScene(L"Game_Scene", std::make_shared<Game_Scene>());

	RegisterScene(L"Stage_1", std::make_shared<ChameleonScene>());
	RegisterScene(L"Stage_2", std::make_shared<TurtleScene>());
	RegisterScene(L"Stage_3", std::make_shared<CrocodileScene>());
	RegisterScene(L"Stage_4", std::make_shared<SeaOtterScene>());
	RegisterScene(L"Stage_5", std::make_shared<PenguinScene>());
	RegisterScene(L"Stage_6", std::make_shared<CapybaraScene>());
	RegisterScene(L"Stage_7", std::make_shared<ToucanScene>());
	RegisterScene(L"Stage_8", std::make_shared<KangarooScene>());
	RegisterScene(L"Stage_9", std::make_shared<SlothScene>());
	
	// Ã¹ ¾À ÁöÁ¤
	LoadScene(L"Stage_1"); //
}

void SceneMgr::Update()
{
	if (UIMgr::GetInst()->isPause) return;
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	if (UIMgr::GetInst()->isPause) return;
	m_pCurScene->Render(_dc);
}

void SceneMgr::LoadScene(const wstring& _scenename)
{
	// ¾ÀÀÌ ÀÖÀ¸¸é
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		m_pCurScene->Init();
	}
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), {_scenename, _scene});
}
