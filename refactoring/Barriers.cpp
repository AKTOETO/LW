#include "pch.h"
#include "Barriers.h"


//===================================//
// � � � � � � � � � � �   � � � � � //
//===================================//

	// ������
void ABCBaseBarrier::Rock()
{
	// ������
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(5), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
};

// ������� ������
void ABCBaseBarrier::HugeRock()
{
	// ������� ������
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(20), GetY());
	LineTo(m_hdc, GetShiftedX(25), GetShiftedY(20));
	LineTo(m_hdc, GetShiftedX(35), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(50), GetShiftedY(50));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(20));
	LineTo(m_hdc, GetX(), GetY());
};

// �������������
void ABCBaseBarrier::Rectangle()
{
	// �������������
	MoveToEx(m_hdc, GetX(), GetY(), NULL);
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(0));
	LineTo(m_hdc, GetShiftedX(100), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(100));
	LineTo(m_hdc, GetShiftedX(0), GetShiftedY(0));
};

void ABCBaseBarrier::Hide()
{
	// ����������� ������ ����� ������
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

void ABCBaseBarrier::Show()
{
	// ����������� ������ ������� ������
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
};

ABCBaseBarrier::ABCBaseBarrier(HDC _hdc, HitBox _box, COLORREF _color)
	:HitBox(_box), m_hdc(_hdc), m_color(_color) 
{}

void ABCBaseBarrier::ProcessDraw()
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
LightBarrier::LightBarrier(HDC _hdc)
	:ABCBaseBarrier(_hdc, { 200,500,50,50 }, YELLOW)
{}

void LightBarrier::Draw()
{
	Rock();
}

// ������� �����������
HugeBarrier::HugeBarrier(HDC _hdc)
	:ABCBaseBarrier(_hdc, { 200,200,100,100 }, GREEN)
{}

void HugeBarrier::Draw()
{
	HugeRock();
}

// �������������
RectBarrier::RectBarrier(HDC _hdc)
	:ABCBaseBarrier(_hdc, { 400, 300, 150,150 }, BLACK)
{}

void RectBarrier::Draw()
{
	Rectangle();
}
