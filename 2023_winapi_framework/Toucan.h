#pragma once
#include "Object.h"

class Texture;
class Toucan :
    public Object
{
public:
    Toucan();
    ~Toucan();
private:
    void Update() override;
    void Render(HDC _dc) override;
public:
    float openTime;
    bool isOpenBeak;
private:
    Texture* texture;
};