#include "pch.h"
#include "TurtleScene.h"
#include "SceneMgr.h"

void TurtleScene::Init()
{

}

void TurtleScene::Update()
{
	//SceneMgr::GetInst()->LoadScene(L"Start_Scene");
}

void TurtleScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void TurtleScene::Release()
{
	Scene::Release();
}
