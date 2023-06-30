#pragma once
#include "MoveableObject.h"

class ABCControllableObject :
    public ABCMoveableObject
{
protected:

    // �������� ������ �������
    virtual void CalcShiftPos() override;

public:
    ABCControllableObject(HDC _hdc, HitBox _box, COLORREF _color, float _speed);
    ~ABCControllableObject();
};

