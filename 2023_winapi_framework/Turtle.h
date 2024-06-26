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
public:
    void SetSpeed(float speed) { _speed = speed; }
    const float GetSpeed() const { return _speed; }
private:
    float _speed;
    Texture* texture;
};

