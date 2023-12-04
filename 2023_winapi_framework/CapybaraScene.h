#pragma once
#include "Scene.h"
class Capybara;
class CapybaraScene :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    vector<Capybara*> capybaraObj;
    int capybaraCnt;
};

