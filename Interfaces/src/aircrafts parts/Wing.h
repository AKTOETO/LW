#pragma once
#include "BaseAircraftPart.h"

// �����
class Wing :
    public BaseAircraftPart
{
protected:

	// ������, ������� ���� ����������
	virtual void DrawModel() override;

public:

	Wing(const HdcPos&);

};

