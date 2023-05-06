#ifndef POINT_H
#define POINT_H

#include "Location.h"

//����������� �����
class Point : public Location
{
protected:
	bool m_visible; //��������� ����� ��� ���
public:
	Point(int InitX, int InitY); //�����������
	virtual ~Point(); //����������
	bool IsVisisble(); //������ ��� ���������� �����
	void SetVisible(bool NewVisible) { m_visible = NewVisible; }; //�������� ����������

	// ����������� �-�� (������� ����������)
	virtual void Show(); //�������� ����� �� ������
	virtual void Hide();//������ ����� 

};//Point

#endif //!POINT_H
