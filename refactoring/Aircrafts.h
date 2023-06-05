#pragma once
#include "pch.h"

// ��������� ����� ��������
class IAircraftPart
{
protected:
	// �����
	virtual void Wing() = 0;

	// �������
	virtual void Fuselage() = 0;

	// ����
	virtual void Window() = 0;

	// ��������� �����
	virtual void RearEngine() = 0;

	// ��������� ��� ������
	virtual void UnderWingEngine() = 0;

	// c������� �������
	virtual void BrokenFuselage() = 0;

	// ��������� �����
	virtual void BrokenWing() = 0;

	// ��������� ����
	virtual void BrokenWindow() = 0;

};

// ����������� ������� ����� ��������
// ��������� ������� ��������� ������ ��������
class ABCAircraft:
	public IAircraftPart,
	public HitBox
{
protected:

	float m_speed;		// �������� ��������
	COLORREF m_color;	// ���� ��������
	HDC m_hdc;			// �������� �������

	// ��������� �������� ��������
	virtual void Draw() = 0;

	// ����� ��������
	// �����
	virtual void Wing() override;

	// �������
	virtual void Fuselage() override;

	// �����������
	virtual void Window() override;

	// ��������� �����
	virtual void RearEngine() override;

	// ��������� ��� ������
	virtual void UnderWingEngine() override;

	// ��������� �������
	virtual void BrokenFuselage() override;

	// ��������� �����
	virtual void BrokenWing() override;

	// ��������� ����
	virtual void BrokenWindow() override;

public:
	// �����������
	ABCAircraft(HDC _hdc, HitBox _box, COLORREF _color, float _speed);
	
	// ����� ������� �������
	void Hide();

	// ����� ����������� �������
	void Show();
	
	// ������� ��������� ��������
	// � ��������� ����������� ��������
	void ProcessDraw();
};

//=================//
// � � � � � � � � //
//=================//

// ������ �������
class LightAircraft :
	public ABCAircraft
{
public:
	// �����������
	LightAircraft(HDC _hdc);

protected:

	// ��������� ��������
	virtual void Draw() override;
};

// ������� �������
class FastAircraft :
	public ABCAircraft
{
public:
	// �����������
	FastAircraft(HDC _hdc);

protected:

	// ��������� ��������
	virtual void Draw() override;
};

// ����� ������� �������
class VeryFastAircraft :
	public ABCAircraft
{
public:
	// �����������
	VeryFastAircraft(HDC _hdc);

protected:

	// ��������� ��������
	virtual void Draw() override;
};

// ��������� �������
class BrokenAircraft :
	public ABCAircraft
{
public:
	// �����������
	BrokenAircraft(HDC _hdc);

protected:

	// ��������� ��������
	virtual void Draw() override;
};