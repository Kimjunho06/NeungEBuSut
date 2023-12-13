#pragma once
#include "Scene.h"
class Sloth;
class SlothScene 
	: public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    vector<Sloth*> slothObj;
    int slothCnt;
};

