#pragma once
#include "Object.h"
class Texture;
class Capybara :
    public Object
{
public:
    Capybara();
    ~Capybara();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void EnterCollision(Collider* _pOther) override;
    void StayCollision(Collider* _pOther) override;
public:
    const bool& GetIsStand() const { return isStand; }
    const bool& GetIsAttatched() const { return isAttatched; }
    void SetIsStand(bool _isStand) { isStand = _isStand; }
    void SetIsStage(bool _isStage) { isStage = _isStage; }
    void SetIsAttatched(bool _isAttatched) { isAttatched = _isAttatched; }
private:
    Texture* texture[2];
    bool isDrag;
    bool isStand;
    bool isStage;
    bool isAttatched;
    Vec2 dragStartPos;
};

