#pragma once
#include "Object.h"

class Texture;
class EndBackground :
    public Object
{
public:
    EndBackground();
    ~EndBackground();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* texture;
};

