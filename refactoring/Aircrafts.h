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

	// �������� �������
	virtual void BrokenFuselage() = 0;
};

// ����������� ������� ����� ��������
// ��������� ������� ��������� ������ ��������
class ABCBaseAircraft:
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

	// ��������� �������
	virtual void BrokenFuselage() override;

public:
	// �����������
	ABCBaseAircraft(HDC _hdc, HitBox _box, COLORREF _color, float _speed);
	
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
	public ABCBaseAircraft
{
public:
	// �����������
	LightAircraft(HDC _hdc);

	// ��������� ��������
	virtual void Draw() override;
};

// ��������� �������
class BrokenAircraft :
	public ABCBaseAircraft
{
public:
	// �����������
	BrokenAircraft(HDC _hdc);

	// ��������� ��������
	virtual void Draw() override;
};

// ������ �������
class FuselageAircraft :
	public ABCBaseAircraft
{
public:
	// �����������
	FuselageAircraft(HDC _hdc);

	// ��������� ��������
	virtual void Draw() override;
};