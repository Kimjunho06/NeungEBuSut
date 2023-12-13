#pragma once
#include "Object.h"
class Texture;
class Chameleon :
    public Object
{
public:
    Chameleon();
    ~Chameleon();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    const int& GetColorIdx() const { return colorIdx; }
private:
    int colorIdx;
    vector<Texture*> textures;
};