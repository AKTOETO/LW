#pragma once
#include "BaseBarrierPart.h"

class Rock :
    public BaseBarrierPart
{
protected:

	// ������, ������� ���� ����������
	virtual void DrawModel() override;

public:

	Rock(const HdcPos&);
};

