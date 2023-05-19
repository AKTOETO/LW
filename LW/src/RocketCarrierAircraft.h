#pragma once
#include "CargoAircraft.h"
class RocketCarrierAircraft :
    public CargoAircraft
{
protected:
    // ������� ��������� ������
    virtual void Draw() override;

public:
    RocketCarrierAircraft(int InitX, int InitY, const HDC& _hdc, int _speed = 10,
        HitBox _hb = { 10,10 }, COLORREF _color = RED, bool is_mooveable = 1);
};

