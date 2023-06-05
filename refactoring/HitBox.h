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
	HitBox(int _x, int _y, int _width, int _height);

	// �����������
	HitBox(Position _pos, int _width, int _height);

	// �������� �������� �� ��� X � �������� ������ �� �������� � ���������
	int GetShiftX(int _percents) const;

	// �������� �������� �� ��� Y � �������� ������ �� �������� � ���������
	int GetShiftY(int _percents) const;

	// �������� ��� ��������� ���������� X ������ �� ��������� ��������
	int GetShiftedX(int _percents) const;

	// �������� ��� ��������� ���������� Y ������ �� ��������� ��������
	int GetShiftedY(int _percents) const;

	// �������� ������ ��������
	const int& GetWidth() const;

	// �������� ������ ��������
	const int& GetHeight() const;

	// ��������� ����� ��������
	HitBox GetHitBox() const;
};