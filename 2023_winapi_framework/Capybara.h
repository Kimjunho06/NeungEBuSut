#pragma once
#include "Object.h"
class Texture;
class Capybara :
    public Object
{
public:
    Capybara();
    ~Capybara();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
    bool isDrag;
    Vec2 dragStartPos;
};

