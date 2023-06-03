#include "../pch.h"
#include "SlowAircraft.h"

SlowAircraft::SlowAircraft(const HdcPos& _cnt)
	:BaseAircraft(5)
{
	// ��������� ����� �������� � ������ �������� ��������
	m_aircraft_parts =
	{
		new Wing(_cnt),
		new Fuselage(_cnt)
	};

	// �������� �����
	m_aircraft_parts[0]->ShiftPos({ 20,40 });
}
