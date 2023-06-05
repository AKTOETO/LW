#include "pch.h"
#include "Position.h"

// �����������
Position::Position(int _x, int _y)
	:m_x(_x), m_y(_y)
{};

// ��������� ���������� ������
// � �������� ����������
void Position::CalcShiftPos(const Position& _pos)
{
	ShiftPos({ _pos.GetX() - m_x, _pos.GetY() - m_y });
}

// �������� ���������� X Y �� _pos
void Position::ShiftPos(const Position& _pos)
{
	m_x += _pos.GetX();
	m_y += _pos.GetY();
}

// ���������� ���������� X
void Position::SetX(int _x)
{
	m_x = _x;
}

// ���������� ���������� Y
void Position::SetY(int _y)
{
	m_y = _y;
}

// ���������� ���������� X Y
void Position::SetPos(int _x, int _y)
{
	SetX(_x);
	SetY(_y);
}
void Position::SetPos(const Position& _pos)
{
	SetX(_pos.GetX());
	SetY(_pos.GetY());
}

// �������� ���������� X
const int& Position::GetX() const
{
	return m_x;
}

// �������� ���������� Y
const int& Position::GetY() const
{
	return m_y;
}

// �������� �������
Position Position::GetPos()
{
	return *this;
}
