#pragma once
#include "Button.h"
class Texture;
class ExitButton :
    public Button
{
public:
    ExitButton();
    ~ExitButton();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClickEvent() override;
private:
    Texture* texture;
};

