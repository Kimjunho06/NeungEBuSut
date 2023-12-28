#pragma once
#include "Object.h"
class Texture;
class RestartButton :
    public Object
{
public:
    RestartButton();
    ~RestartButton();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void OnClickEvent();
private:
    Texture* texture;

};

