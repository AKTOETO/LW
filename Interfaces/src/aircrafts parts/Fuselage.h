#pragma once
#include "BaseAircraftPart.h"

// �������
class Fuselage :
	public BaseAircraftPart
{
protected:

	// ������, ������� ���� ����������
	virtual void DrawModel() override;

public:

	Fuselage(const HdcPos&);

};

