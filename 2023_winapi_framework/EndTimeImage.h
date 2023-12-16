#pragma once
#include "Button.h"
class Texture;
class EndTimeImage :
    public Button
{
public:
    EndTimeImage();
    ~EndTimeImage();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
};

