#pragma once
#include "BaseAircraftPart.h"
class Window :
    public BaseAircraftPart
{
protected:

	// ������, ������� ���� ����������
	virtual void DrawModel() override;

public:

	Window(const HdcPos&);
};

