#pragma once
#include "Slider.h"
class Texture;
class TestSlider :
    public Slider
{
public:
    TestSlider();
    virtual ~TestSlider();
public:
    void Init() override;
    void Update() override;
    void Render(HDC _dc) override;
public:
    Texture* texture;
};

