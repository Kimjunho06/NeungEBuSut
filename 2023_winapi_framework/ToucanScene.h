#pragma once
#include "Scene.h"
class Toucan;
class ToucanScene : public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    vector<Toucan*> toucans;
    int totalToucan;
    int totalOpenToucan;
};

