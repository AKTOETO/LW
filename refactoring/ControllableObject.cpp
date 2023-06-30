#include "pch.h"
#include "ControllableObject.h"

void ABCControllableObject::CalcShiftPos()
{
	// ��������� ������� ������
	// ���� ������ ������� ������, ��������� �����
	if (KEY_DOWN(K_FORWARD))
	{
		m_shift = { 0, -int(m_speed) };
		m_dir = DIR::UP;
	}

	// ���� ������ ������� �����, ��������� ����
	else if (KEY_DOWN(K_BACKWARD))
	{
		m_shift = { 0, int(m_speed) };
		m_dir = DIR::DOWN;
	}

	// ���� ������ ������� �����, ��������� �����
	else if (KEY_DOWN(K_LEFTWARD))
	{
		m_shift = { -int(m_speed), 0 };
		m_dir = DIR::LEFT;
	}

	// ���� ������ ������� ������, ��������� ������
	else if (KEY_DOWN(K_RIGHTWARD))
	{
		m_shift = { int(m_speed), 0 };
		m_dir = DIR::RIGHT;
	}
	else
	{
		m_shift = { 0,0 };
		m_dir = DIR::STOP;
	}

}

ABCControllableObject::ABCControllableObject(HDC _hdc, HitBox _box, COLORREF _color, float _speed)
	:ABCMoveableObject(_hdc, _box, _color, _speed)
{
}

ABCControllableObject::~ABCControllableObject()
{
}
