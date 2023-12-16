#pragma once
#include "Object.h"
class Texture;
class EndTimeImage :
    public Object
{
public:
    EndTimeImage();
    ~EndTimeImage();
public:
    void Update() override;
    void Render(HDC _dc) override;

private:
    Texture* texture;
};

