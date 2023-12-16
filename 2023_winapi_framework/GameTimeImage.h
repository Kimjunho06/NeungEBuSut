#pragma once
#include "Object.h"
class Texture;
class GameTimeImage :
    public Object
{
public:
    GameTimeImage();
    ~GameTimeImage();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
};

