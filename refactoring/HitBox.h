#pragma once
#include "Position.h"

// ��������� ���� ������ �������� �������
class HitBox
	: public Position
{
protected:

	int m_width;	// ������
	int m_height;	// ������

public:

	// ����������� � �����������
	HitBox(int _x, int _y,int _width, int _height)
		: Position(_x, _y), m_width(_width), m_height(_height) {};

	// �����������
	HitBox(Position _pos, int _width, int _height)
		: Position(_pos), m_width(_width), m_height(_height) {};

	// �������� �������� �� ��� X � �������� ������ �� �������� � ���������
	int GetShiftX(int _percents) const { return (m_width * _percents / 100); }

	// �������� �������� �� ��� Y � �������� ������ �� �������� � ���������
	int GetShiftY(int _percents) const { return (m_height * _percents / 100); };

	// �������� ��� ��������� ���������� X ������ �� ��������� ��������
	int GetShiftedX(int _percents) const { return m_x + GetShiftX(_percents); }

	// �������� ��� ��������� ���������� Y ������ �� ��������� ��������
	int GetShiftedY(int _percents) const { return m_y + GetShiftY(_percents); }

	// �������� ������ ��������
	const int& GetWidth() const { return m_width; }

	// �������� ������ ��������
	const int& GetHeight() const { return m_height; }

	// ��������� ����� ��������
	HitBox GetHitBox() const { return *this; }
};