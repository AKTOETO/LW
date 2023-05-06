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

//// ����������� �� ��������
//void Point::Drag()
//{
//	// ���� �� ������ Q
//	while (!KEY_DOWN(81))
//	{
//		// A - ����
//		if (KEY_DOWN(65)) MoveTo(m_x - 10, m_y);
//		// W - �����
//		else if (KEY_DOWN(87)) MoveTo(m_x, m_y - 10);
//		// D - ������
//		else if (KEY_DOWN(68)) MoveTo(m_x + 10, m_y);
//		// S - ����
//		else if (KEY_DOWN(83)) MoveTo(m_x, m_y + 10);
//		Sleep(10);
//	}
//}
//
////����������� ������ �� ����� �����������
//void Point::MoveTo(int NewX, int NewY)
//{
//	Hide();//������ ������ �� ������� ����������
//	m_x = NewX; //������ ���������� ������
//	m_y = NewY;
//	Show();//�������� ������ �� ����� �����������
//}
