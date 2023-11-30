#pragma once
#include "Object.h"
class Texture;
class Clam :
    public Object
{
public:
    Clam();
    ~Clam();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
    float hitTime;
    int cnt;
    bool isHit;
};

