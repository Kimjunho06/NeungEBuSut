#pragma once
#include "Object.h"
class Texture;
class Penguin :
    public Object
{
public:
    Penguin();
    ~Penguin();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    bool isClick;
private:
    Texture* texture;
    int speed;
};

