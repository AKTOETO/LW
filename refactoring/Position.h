#pragma once
#include "pch.h"

// ����� �������
class Position
{
protected:

	int m_x;	// ���������� �
	int m_y;	// ���������� �

public:

	// �����������
	Position(int _x, int _y);

	// ��������� ���������� ������
	// � �������� ����������
	void CalcShiftPos(const Position& _pos);

	// �������� ���������� X Y �� _pos
	void ShiftPos(const Position& _pos);

	// ���������� ���������� X
	void SetX(int _x);

	// ���������� ���������� Y
	void SetY(int _y);

	// ���������� ���������� X Y
	void SetPos(int _x, int _y);
	void SetPos(const Position& _pos);

	// �������� ���������� X
	const int& GetX() const;

	// �������� ���������� Y
	const int& GetY() const;

	// �������� �������
	Position GetPos();
};