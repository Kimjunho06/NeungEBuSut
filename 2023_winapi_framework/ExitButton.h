#pragma once
#include "Object.h"
class Texture;
class ExitButton :
    public Object
{
public:
    ExitButton();
    ~ExitButton();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClickEvent();
private:
    Texture* texture[2];
};

