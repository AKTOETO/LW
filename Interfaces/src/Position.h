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
	Position(int _x, int _y) :m_x(_x), m_y(_y) {};

	// ��������� ���������� ������
	// � �������� ����������
	void CalcShiftPos(const Position& _pos) { ShiftPos({ _pos.GetX() - m_x, _pos.GetY() - m_y}); }

	// �������� ���������� X Y �� _pos
	void ShiftPos(const Position& _pos) { m_x += _pos.GetX(); m_y += _pos.GetY(); }

	// ���������� ���������� X
	void SetX(int _x) { m_x = _x; }

	// ���������� ���������� Y
	void SetY(int _y) { m_y = _y; }

	// ���������� ���������� X Y
	void SetPos(int _x, int _y) { SetX(_x); SetY(_y); }
	void SetPos(const Position& _pos) { SetX(_pos.GetX()); SetY(_pos.GetY()); }

	// �������� ���������� X
	const int& GetX() const { return m_x; }

	// �������� ���������� Y
	const int& GetY() const { return m_y; }

	// �������� �������
	Position GetPos() { return *this; }
};