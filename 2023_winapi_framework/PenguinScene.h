#pragma once
#include "Scene.h"
class Penguin;
class PenguinScene :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    vector<Penguin*> penguinObj;
    int penguinCnt;
};

