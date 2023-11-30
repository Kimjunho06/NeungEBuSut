#pragma once
#include "Button.h"
class Texture;
class TurtleButton :
    public Button
{
public:
    TurtleButton();
    ~TurtleButton();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void OnClickEvent() override;
public:
    const float& GetSpeed() const { return speed; }
private:
    float speed;
    Texture* texture;
};

