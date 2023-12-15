#pragma once
#include "Object.h"
class Texture;
class StageBackground :
    public Object
{
public:
    StageBackground();
    ~StageBackground();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
};

