#pragma once
#include "Object.h"
class Texture;
class StagePanel :
    public Object
{
public:
    StagePanel();
    ~StagePanel();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
};

