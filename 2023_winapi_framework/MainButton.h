#pragma once
#include "Object.h"
class Texture;
class MainButton :
    public Object
{
public:
    MainButton();
    ~MainButton();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void OnClickEvent();
private:
    Texture* texture;
};

