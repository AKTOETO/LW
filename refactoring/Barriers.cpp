#include "pch.h"
#include "Barriers.h"


//===================================//
// � � � � � � � � � � �   � � � � � //
//===================================//

// ������
void ABCBarrier::Rock()
{
	// ������
	MoveToEx(m_hdc, GetShiftedX(10), GetShiftedY(0), NULL);
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(10));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(90));
	LineTo(m_hdc, GetShiftedX(10), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(90));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(10));
	LineTo(m_hdc, GetShiftedX(90), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(10), GetShiftedY(0));
}

// ����� ��������� ��������
void ABCBarrier::Upgrade()
{
	MoveToEx(m_hdc, GetShiftedX(50), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(0));
}

// ����� ��������� ��������
void ABCBarrier::Downgrade()
{
	MoveToEx(m_hdc, GetShiftedX(50), GetShiftedY(100), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(70), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(30), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(80));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(100));
}

void ABCBarrier::Hide()
{
	// ����������� ������ ����� ������
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

void ABCBarrier::Show()
{
	// ����������� ������ ������� ������
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

ABCBarrier::ABCBarrier(HDC _hdc, HitBox _box, COLORREF _color)
	:HitBox(_box), m_hdc(_hdc), m_color(_color)
{}

void ABCBarrier::ProcessDraw()
{
	// ������ ������
	Hide();

	// ���������� ������
	Show();
}

//=======================//
// � � � � � � � � � � � //
//=======================//

// ������ �����������
Mountain::Mountain(HDC _hdc)
	:ABCBarrier(_hdc, { 100,400,100,100 }, BLACK)
{}

void Mountain::Draw()
{
	Rock();
}

// ������� �����������
UpgradeTower::UpgradeTower(HDC _hdc)
	:ABCBarrier(_hdc, { 400,200,80,100 }, GREEN)
{}

void UpgradeTower::Draw()
{
	Upgrade();
}

// �������������
DowngradeTower::DowngradeTower(HDC _hdc, HitBox _hb)
	:ABCBarrier(_hdc, _hb, RED)
{}

void DowngradeTower::Draw()
{
	Downgrade();
}

InherDowngradeTower::InherDowngradeTower(HDC _hdc)
	:DowngradeTower(_hdc, {200, 300, 200, 200})
{
}

void InherDowngradeTower::Draw()
{
	Rock();
}
