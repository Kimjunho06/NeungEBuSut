#pragma once
class Collider;
class Animator;
class Object
{
public:
	Object();
	virtual ~Object();
//public:	// 크기, 위치
	//POINT m_ptPos;
	//POINT m_ptScale;
public:
	virtual void Update() abstract;
	virtual void Render(HDC _dc) abstract;
	virtual void FinalUpdate() final;
	virtual void EnterCollision(Collider* _pOther);
	virtual void ExitCollision(Collider* _pOther);
	virtual void StayCollision(Collider* _pOther);
	void Component_Render(HDC _dc);
public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void SetScaleOffset(Vec2 _vScaleOffset) { m_vScaleOffset = _vScaleOffset; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetScale() const { return m_vScale; }
	const Vec2& GetScaleOffset() const { return m_vScaleOffset; }
	Collider* GetCollider() const 
	{ return m_pCollider; }
	Animator* GetAnimator()
	{
		return m_pAnimator;
	}
	const wstring& GetName() const { return m_strName; }
	void SetName(wstring _name) { m_strName = _name; }
	bool GetIsDead() const { return !m_IsAlive; }
private:
	void SetDead() { m_IsAlive = false; }
	friend class EventMgr;
public:
	void CreateCollider();
	void CreateAnimator();
public:
	bool IsClickAble(Object* obj);
private:
	Vec2 m_vPos; // 위치
	Vec2 m_vScale; // 크기
	Vec2 m_vScaleOffset; // 크기 가중치
	Collider* m_pCollider;
	wstring m_strName; // 이름.
	bool m_IsAlive;
	Animator* m_pAnimator;
};

