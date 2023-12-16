#pragma once
#include "Button.h"
class Texture;
class GameTimeImage :
    public Button
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

