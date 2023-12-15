#pragma once
#include "Object.h"
class Texture;
class MainBackground :
    public Object
{
public:
    MainBackground();
    ~MainBackground();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
};

