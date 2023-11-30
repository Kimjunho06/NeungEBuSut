#pragma once
#include "Object.h"
class Texture;
class Fish :
    public Object
{
public:
    Fish();
    ~Fish();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    Texture* texture;
    float speed;
    DIRECTION dir;
};

