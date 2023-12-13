#pragma once
#include "Object.h"
class Texture;
class Kangaroo :
    public Object
{
public:
    Kangaroo();
    ~Kangaroo();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void StayCollision(Collider* _pOther) override;
    void EnterCollision(Collider* _pOther) override;
public:
    bool isDie;
    bool isfall;
private:
    Texture* texture;
    float jumpTime;
    bool isCanJump;
    bool isJump;
};

