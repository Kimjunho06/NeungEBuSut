#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "UI.h"
Scene::Scene()
{
}

Scene::~Scene()
{
	Release();
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if(!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->Update();
		}
	}
	
	for (UINT i = 0; i < (UINT)UI_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecUi[i].size(); ++j)
		{
			m_vecUi[i][j]->Update();
		}
	}
}

void Scene::FinalUpdate()
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			m_vecObj[i][j]->FinalUpdate();
		}
	}
}

void Scene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			if (!m_vecObj[i][j]->GetIsDead())
			{
				m_vecObj[i][j]->Render(_dc);
				++j;
			}
			else
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
		}
	}

	for (UINT i = 0; i < (UINT)UI_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecUi[i].size(); ++j)
		{
			m_vecUi[i][j]->Render(_dc);
		}
	}
}

void Scene::Release()
{
	for (UINT i = 0; i < (UINT)UI_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecUi[i].size(); ++j)
		{
			delete m_vecUi[i][j];
		}
		m_vecUi[i].clear();
	}

	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
		}
		m_vecObj[i].clear();
	}
}
