#pragma once
#include "UI.h"
class Button :
    public UI
{
public:
    Button();
    ~Button();
public:
    virtual void Update() abstract;
    virtual void Render(HDC _dc) abstract;
public:
    virtual void OnClickEvent() abstract;
public:
    bool isClick;
};

