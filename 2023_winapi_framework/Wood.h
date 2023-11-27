#pragma once
#include "Object.h"
class Texture;
class Wood :
    public Object
{
public:
    Wood();
    ~Wood();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
};

