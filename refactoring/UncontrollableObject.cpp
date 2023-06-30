#include "pch.h"
#include "UncontrollableObject.h"

void ABCUncontrollableObject::CalcShiftPos()
{
	switch (m_dir)
	{
		// ��������� �����
	case DIR::LEFT:
		m_shift = { -int(m_speed), 0 };
		break;

		// ��������� �����
	case DIR::UP:
		m_shift = { 0, -int(m_speed) };
		break;

		// ��������� ������
	case DIR::RIGHT:
		m_shift = { int(m_speed), 0 };
		break;

		// ��������� ����
	case DIR::DOWN:
		m_shift = { 0, int(m_speed) };
		break;

	case DIR::STOP:
		m_shift = { 0,0 };
		break;
	}
}

ABCUncontrollableObject::ABCUncontrollableObject(
	HDC _hdc, HitBox _box, COLORREF _color, float _speed, DIR _dir
)
	:ABCMoveableObject(_hdc, _box, _color, _speed), m_dir(_dir)
{
}

ABCUncontrollableObject::~ABCUncontrollableObject()
{
}
