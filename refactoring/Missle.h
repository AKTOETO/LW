#pragma once
#include "UncontrollableObject.h"

class Missile :
    public ABCUncontrollableObject
{
protected:

    // ��������� ������
    virtual void Draw() override;

public:

    // �����������
    Missile(HDC _hdc, Position _box);

};

