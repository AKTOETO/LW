#include "pch.h"
#include "Point.h"

//�����������
Point::Point(int InitX, int InitY)
	: Location(InitX, InitY)
{
	m_visible = false;
}
//����������
Point::~Point()
{
	//emty body
};

//������ ��� ���������� �����
bool Point::IsVisisble()
{
	return m_visible;
};
//�������� ����� �� ������
void Point::Show()
{
	m_visible = true;
	SetPixel(hdc, m_x, m_y, RGB(255, 0, 0));//������ ����� ������������� ������
	SetPixel(hdc, m_x + 1, m_y, RGB(255, 0, 0));//������ ����� ������������� ������
	SetPixel(hdc, m_x, m_y + 1, RGB(255, 0, 0));//������ ����� ������������� ������
	SetPixel(hdc, m_x + 1, m_y + 1, RGB(255, 0, 0));//������ ����� ������������� ������
}


/*-------------------*/
/*       Point       */
/*-------------------*/

//������ ����� �� ������
void Point::Hide()
{
	m_visible = false;
	SetPixel(hdc, m_x, m_y, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, m_x + 1, m_y, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, m_x, m_y + 1, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, m_x + 1, m_y + 1, RGB(0, 0, 0));//������ ����� ������������ ������

}