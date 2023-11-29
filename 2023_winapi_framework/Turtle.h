#pragma once
#include "Object.h"
class Texture;
class Turtle :
    public Object
{
public:
    Turtle();
    ~Turtle();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void EnterCollision(Collider* _pOther) override;
private:
    int speed;
    Texture* texture;
};

