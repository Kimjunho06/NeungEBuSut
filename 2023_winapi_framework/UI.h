#pragma once
class UI
{
public:
	UI();
	virtual ~UI();
public:
	virtual void Update() abstract;
	virtual void Render(HDC _dc) abstract;
public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void SetScaleOffset(Vec2 _vScaleOffset) { m_vScaleOffset = _vScaleOffset; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetScale() const { return m_vScale; }
	const Vec2& GetScaleOffset() const { return m_vScaleOffset; }
public:
	bool IsClickAble(UI* ui);
public:
	Vec2 m_vPos;
	Vec2 m_vScale;
	Vec2 m_vScaleOffset;
	bool isEnable;
};

