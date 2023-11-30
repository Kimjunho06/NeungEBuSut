#pragma once
#include "UI.h"
class Slider :
    public UI
{
public:
    Slider();
    virtual ~Slider();
public:
    virtual void Update() abstract;
    virtual void Render(HDC _dc) abstract;
public:
    int value;
};

