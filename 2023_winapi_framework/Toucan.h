#pragma once
#include "Object.h"

class Texture;
class Toucan : public Object
{
public:
	Toucan();
	~Toucan();
public:
	void Update() override;
	void Render(HDC _dc) override;
private:
	Texture* texture;
	bool isOpenBeak;
};

