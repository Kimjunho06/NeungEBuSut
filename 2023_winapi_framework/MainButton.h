#pragma once
#include "Button.h"
class Texture;
class MainButton :
    public Button
{
public:
    MainButton();
    ~MainButton();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void OnClickEvent() override;
private:
    Texture* texture;
};

