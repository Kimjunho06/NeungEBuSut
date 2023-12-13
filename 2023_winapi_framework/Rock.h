#pragma once
#include "Object.h"
class Texture;
class Rock :
    public Object
{
public:
    Rock();
    ~Rock();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    bool isKangarooRock;
private:
    Texture* texture;
    int speed;
};

