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
	SlowAircraft(int InitX, int InitY, const HDC& _hdc, int _speed = 5, HitBox _hb = { 10,10 }); //�����������
	~SlowAircraft(); //����������
};
#endif //!SLOWAIRCRAFT_H