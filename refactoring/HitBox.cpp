#include "pch.h"
#include "HitBox.h"

// ����������� � �����������
HitBox::HitBox(int _x, int _y, int _width, int _height)
	: Position(_x, _y), m_width(_width), m_height(_height)
{};

// �����������
HitBox::HitBox(Position _pos, int _width, int _height)
	: Position(_pos), m_width(_width), m_height(_height)
{};

// �������� �������� �� ��� X � �������� ������ �� �������� � ���������
int HitBox::GetShiftX(int _percents) const
{
	return (m_width * _percents / 100);
}

// �������� �������� �� ��� Y � �������� ������ �� �������� � ���������
int HitBox::GetShiftY(int _percents) const
{
	return (m_height * _percents / 100);
}

// �������� ��� ��������� ���������� X ������ �� ��������� ��������
int HitBox::GetShiftedX(int _percents) const
{
	return m_x + GetShiftX(_percents);
}

// �������� ��� ��������� ���������� Y ������ �� ��������� ��������
int HitBox::GetShiftedY(int _percents) const
{
	return m_y + GetShiftY(_percents);
}

// �������� ������ ��������
const int& HitBox::GetWidth() const
{
	return m_width;
}

// �������� ������ ��������
const int& HitBox::GetHeight() const
{
	return m_height;
}

Position HitBox::GetShiftedPosition(int _percents_x, int _percents_y) const
{
	return Position(GetShiftedX(_percents_x), GetShiftedY(_percents_y));
}

// ��������� ����� ��������
HitBox HitBox::GetHitBox() const
{
	return *this;
}
