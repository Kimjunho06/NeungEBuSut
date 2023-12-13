#pragma once
#include "Object.h"
class Texture;
class Sloth :
    public Object
{
public:
    Sloth();
    ~Sloth();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void EnterCollision(Collider* _pOther) override;
public:
    bool isHang;
private:
    Texture* texture;
    bool isDrag;
    Vec2 dragStartPos;
};

