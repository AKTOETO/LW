#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include "ControllableObject.h"


class Aircraft : public ControllableObject
{
protected:
	// ������� ��������� ������
	virtual void Draw() override;

public:
	Aircraft(int InitX, int InitY, const HDC& _hdc, int _speed = 10, HitBox _hb = {10,10}, COLORREF _color = RED, bool is_mooveable = 1); //�����������
	virtual ~Aircraft(); //����������

	// ����� ����������� ������ ��������� ������ � ��������� �������
	/*virtual void ProcessLogic(float _time) override;*/

};

#endif //!AIRCRAFT_H