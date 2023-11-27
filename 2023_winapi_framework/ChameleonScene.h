#pragma once
#include "Scene.h"
class Chameleon;
class ColorObject;
class ChameleonScene :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    int matchCnt;
    int clearCnt;
    int chameleonCnt;
    vector<Chameleon*> chameleonObj;
    vector<ColorObject*> chameleonColorObj;
};

