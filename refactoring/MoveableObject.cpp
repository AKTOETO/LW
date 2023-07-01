#include "pch.h"
#include "MoveableObject.h"

ABCMoveableObject::ABCMoveableObject(
	HDC _hdc, HitBox _box, COLORREF _color, float _speed
)
	:HitBox(_box), m_hdc(_hdc), m_color(_color),
	m_speed(_speed), m_shift({0,0}), m_dir(DIR::DOWN)
{}

ABCMoveableObject::~ABCMoveableObject()
{}

// ����� ������� �������
void ABCMoveableObject::Hide()
{
	// ����������� ������ ����� ������
	HPEN Pen = CreatePen(PS_SOLID, 3, WHITE_GRAY);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
}

// ����� ����������� �������
void ABCMoveableObject::Show()
{
	// ����������� ������ ������� ������
	HPEN Pen = CreatePen(PS_SOLID, 3, m_color);
	SelectObject(m_hdc, Pen);
	Draw();
	DeleteObject(Pen);
}

// ��������� �������������� �������
void ABCMoveableObject::ProcessDraw()
{
	// ������ ������
	Hide();

	// ������ ������
	CalcShiftPos();

	// ����� ������ ������ �������
	ShiftPos(m_shift);

	// ���������� ������
	Show();
}

void ABCMoveableObject::Reposition(Position _pos)
{
	Hide();
	Position::SetPos(_pos);
	Show();
}


const DIR& ABCMoveableObject::GetDir() const
{
	return m_dir;
}