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
    void SetColorIdx(int _colorIdx) { colorIdx = _colorIdx; }
    const int& GetColorIdx() const { return colorIdx; }
private:
    int colorIdx;
    vector<Texture*> textures;
};