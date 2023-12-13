#pragma once
#include "Object.h"
class Texture;
class Flag :
    public Object
{
public:
    Flag();
    ~Flag();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    bool isKangarooFlag;
private:
    Texture* texture;
};

