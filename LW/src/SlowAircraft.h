#ifndef SLOWAIRCRAFT_H
#define SLOWAIRCRAFT_H

#include "Aircraft.h"
class SlowAircraft :
    public Aircraft
{
protected:
	// ������� ��������� ������
	virtual void Draw() override;

public:
	SlowAircraft(
		int InitX, int InitY, const HDC& _hdc, int _speed = 10,
		HitBox _hb = { 10,10 }, COLORREF _color = RED, bool is_mooveable = 1
	); //�����������
};
#endif //!SLOWAIRCRAFT_H