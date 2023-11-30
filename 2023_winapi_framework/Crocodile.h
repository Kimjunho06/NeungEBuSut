#pragma once
#include "Object.h"
class Texture;
class Crocodile :
    public Object
{
public:
    Crocodile();
    ~Crocodile();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void EnterCollision(Collider* _pOther) override;
    void StayCollision(Collider* _pOther) override;
private:
    Texture* texture;
    float biteTime;
    bool isBite;
};

