#pragma once
#include "Button.h"
class Texture;
class RestartButton :
    public Button
{
public:
    RestartButton();
    ~RestartButton();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void OnClickEvent() override;
private:
    Texture* texture;

};

