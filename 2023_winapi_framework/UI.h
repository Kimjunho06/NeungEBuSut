#pragma once
class UI
{
public:
	UI();
	virtual ~UI();
public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC _dc) abstract;
public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetScale() const { return m_vScale; }
public:
	bool IsClickAble();
public:
	Vec2 m_vPos;
	Vec2 m_vScale;
	bool isEnable;
};

