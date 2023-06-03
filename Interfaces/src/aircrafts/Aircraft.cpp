#include "../pch.h"
#include "Aircraft.h"

Aircraft::Aircraft(const HdcPos& _cnt)
	:BaseAircraft(10)
{
	// ��������� ����� �������� � ������ �������� ��������
	m_aircraft_parts =
	{
		new Wing(_cnt),
		new Fuselage(_cnt)
	};

	// �������� �����
	m_aircraft_parts[0]->ShiftPos({ 40,20 });

	// ���������� ��� ����� ��������
	SetVisible();
}
