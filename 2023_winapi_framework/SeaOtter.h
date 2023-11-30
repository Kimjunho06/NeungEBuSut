#pragma once
#include "Object.h"
class Texture;
class SeaOtter :
    public Object
{
public:
    SeaOtter();
    ~SeaOtter();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
    float hitTime;
    bool isHit;
};

