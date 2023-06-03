#pragma once
#include "pch.h"

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

class ABCBaseAircraft:
	public IAircraftPart,
	public HitBox
{
protected:
	float m_speed;
	COLORREF m_color;
	HDC m_hdc;

	// ��������� �������� ��������
	virtual void Draw() = 0;

	// ����� ��������
	virtual void Wing() override 
	{
		// ����� ������
		MoveToEx(m_hdc, GetShiftedX(50), GetShiftedY(75), NULL);
		LineTo(m_hdc, GetShiftedX(65), GetShiftedY(0));
		LineTo(m_hdc, GetShiftedX(60), GetShiftedY(100));
	};

	virtual void Fuselage() override
	{
		MoveToEx(m_hdc, GetX(), GetY(), NULL);
		LineTo(m_hdc, GetShiftedX(20), GetY());
		LineTo(m_hdc, GetShiftedX(25), GetShiftedY(40));
		LineTo(m_hdc, GetShiftedX(90), GetShiftedY(40));
		LineTo(m_hdc, GetShiftedX(100), GetShiftedY(70));
		LineTo(m_hdc, GetShiftedX(90), GetShiftedY(100));
		LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
		LineTo(m_hdc, GetX(), GetY());
	};

	virtual void Window() override
	{
		// ����
		MoveToEx(m_hdc, GetX(), GetY(), NULL);
		LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
		LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
		LineTo(m_hdc, GetShiftedX(0), GetShiftedY(100));
		LineTo(m_hdc, GetShiftedX(0), GetShiftedY(0));
	};

	virtual void BrokenFuselage() override
	{
		MoveToEx(m_hdc, GetX(), GetY(), NULL);
		LineTo(m_hdc, GetShiftedX(20), GetY());
		LineTo(m_hdc, GetShiftedX(25), GetShiftedY(40));
		LineTo(m_hdc, GetShiftedX(90), GetShiftedY(40));
		LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
		LineTo(m_hdc, GetX(), GetY());
	};

private:

public:
	ABCBaseAircraft(HDC _hdc, HitBox _box, COLORREF _color, float _speed)
		:HitBox(_box),m_hdc(_hdc), m_color(_color), m_speed(_speed) {};
	
	void Hide()
	{
		// ����������� ������ ����� ������
		HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
		SelectObject(m_hdc, Pen);
		Draw();
		DeleteObject(Pen);
	};

	void Show()
	{
		// ����������� ������ ������� ������
		HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
		SelectObject(m_hdc, Pen);
		Draw();
		DeleteObject(Pen);
	};
	
	void ProcessDraw()
	{
		// ������ ������
		Hide();

		Position shift(0,0);
		// ��������� ������� ������
		// ���� ������ ������� ������, ��������� �����
		if (KEY_DOWN(K_FORWARD))
			shift = { 0, -int(m_speed) };

		// ���� ������ ������� �����, ��������� ����
		else if (KEY_DOWN(K_BACKWARD))
			shift = { 0, int(m_speed) };

		// ���� ������ ������� �����, ��������� ����
		else if (KEY_DOWN(K_LEFTWARD))
			shift = { -int(m_speed),0 };

		// ���� ������ ������� �����, ��������� ����
		else if (KEY_DOWN(K_RIGHTWARD))
			shift = { int(m_speed),0 };

		// ����� ������ ������ �������
		ShiftPos(shift);

		Show();
	}
};

// ������ �������
class Aircraft :
	public ABCBaseAircraft
{
public:
	Aircraft(HDC _hdc) :
		ABCBaseAircraft(_hdc, { 0,0,100,50 }, RED, 10)
	{}

	// ��������� ��������
	virtual void Draw() override
	{
		Fuselage();
		Wing();
	}
};

// ��������� �������
class BrokenAircraft :
	public ABCBaseAircraft
{
public:
	BrokenAircraft(HDC _hdc):
		ABCBaseAircraft(_hdc, {0,0,100,50}, GREEN, 0)
	{}

	// ��������� ��������
	virtual void Draw() override
	{
		BrokenFuselage();
		Wing();
	}
};

// ������ �������
class FuselageAircraft :
	public ABCBaseAircraft
{
public:
	FuselageAircraft(HDC _hdc):
		ABCBaseAircraft(_hdc, {0,0,100,50}, YELLOW, 5)
	{}

	// ��������� ��������
	virtual void Draw() override
	{
		Fuselage();
	}
};