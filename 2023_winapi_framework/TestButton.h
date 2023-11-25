#pragma once
#include "Button.h"
class Texture;
class TestButton :
    public Button
{
public:
    TestButton();
    ~TestButton();
public:
    void Init() override;
    void Update() override;
    void Render(HDC _dc) override;
public:
    void OnClickEvent() override;
public:
    Texture* texture;
};

