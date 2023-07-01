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

ABCBarrier::ABCBarrier(HDC _hdc, HitBox _box, COLORREF _color)
	:ABCUncontrollableObject(_hdc, _box, _color, BARRIER_SPEED, DIR::LEFT)
{}


//=======================//
// � � � � � � � � � � � //
//=======================//

// ������ �����������
Mountain::Mountain(HDC _hdc)
	:ABCBarrier(_hdc, { GF_RAND_WIDTH, GF_RAND_HIGHT, 100, 100 }, BLACK)
{}

Mountain::Mountain(HDC _hdc, Position _pos)
	:ABCBarrier(_hdc, { _pos, 100, 100 }, BLACK)
{}

void Mountain::Draw()
{
	Rock();
}

// ������� �����������
UpgradeTower::UpgradeTower(HDC _hdc)
	:ABCBarrier(_hdc, { GF_RAND_WIDTH, GF_RAND_HIGHT,80,100 }, GREEN)
{}

void UpgradeTower::Draw()
{
	Upgrade();
}

// �������������
DowngradeTower::DowngradeTower(HDC _hdc)
	:ABCBarrier(_hdc, { GF_RAND_WIDTH, GF_RAND_HIGHT,80,100 }, RED)
{}

void DowngradeTower::Draw()
{
	Downgrade();
}
