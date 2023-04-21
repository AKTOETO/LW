#include <Windows.h>
#include "Header.h"

//���������� ����������
extern HDC hdc;//�������� ����������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
/*-----------------------------------------------------------------*/
/*     � � � � � � � � � �    � � � � � � �    � � � � � � �       */
/*-----------------------------------------------------------------*/

/*-----------------------------------*/
/*          ����� Location           */
/*-----------------------------------*/

//�����������
Location::Location(int InitX, int InitY)
{
	X = InitX;
	Y = InitY;
}//Location()

//����������
Location::~Location()
{
	//������ ����
}

//�������� �������� ���� X READ
int Location::GetX()
{
	return X;
};

//�������� �������� ���� Y
int Location::GetY()
{
	return Y;
};
/*-----------------------------------*/
/*            ����� Point            */
/*-----------------------------------*/

//�����������
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = false;
}
//����������
Point::~Point()
{
	//emty body
};

//������ ��� ���������� �����
bool Point::IsVisisble()
{
	return Visible;
};
//�������� ����� �� ������
void Point::Show()
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));//������ ����� ������������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));//������ ����� ������������� ������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));//������ ����� ������������� ������
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));//������ ����� ������������� ������

}
//������ ����� �� ������
void Point::Hide()
{
	Visible = false;
	SetPixel(hdc, X, Y, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));//������ ����� ������������ ������

}
//����������� ������ �� ����� �����������
void Point::MoveTo(int NewX, int NewY)
{
	Hide();//������ ������ �� ������� ����������
	X = NewX; //������ ���������� ������
	Y = NewY;
	Show();//�������� ������ �� ����� �����������
}

/*-----------------------------------*/
/*          ����� Aircraft           */
/*-----------------------------------*/
//�����������
Aircraft::Aircraft(int InitX, int InitY, int InitRadius, int InitEyeC) :Point(InitX, InitY)
{
	Radius = InitRadius;
	EyeColor = InitEyeC;
}
//����������
Aircraft::~Aircraft()
{
};


//�������� ���� �� ������
void Aircraft::Show()
{
	Visible = true;
	//������� ���� � ���� ����
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	//������ ���� �������� 
	SelectObject(hdc, PenBlack);
	//�������� ������ ����
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);


	PenBlack = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, PenBlack);
	//�������� ������ ������� �����
	Ellipse(hdc, X + 0.416 * Radius - 0.167 * Radius, Y - 0.277 * Radius - 0.167 * Radius, X + 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius + 0.167 * Radius);
	//�������� ������ ������ �����
	Ellipse(hdc, X - 0.416 * Radius - 0.167 * Radius, Y - 0.277 * Radius - 0.167 * Radius, X - 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius + 0.167 * Radius);

	//����� ����� ����
	HBRUSH Brush;
	switch (EyeColor)
	{
	case Black:
		Brush = CreateSolidBrush(RGB(0, 0, 0));
		break;
	case Brown:
		Brush = CreateSolidBrush(RGB(138, 97, 36));
		break;
	case Green:
		Brush = CreateSolidBrush(RGB(65, 161, 31));
		break;
	case Red:
		Brush = CreateSolidBrush(RGB(229, 18, 18));
		break;
	default:
		Brush = CreateSolidBrush(RGB(0, 0, 0));
	}
	//������������ ���� (�������)
	SelectObject(hdc, Brush);
	//������
	Ellipse(hdc, X + 0.416 * Radius, Y - 0.277 * Radius - 0.167 * Radius / 2, X + 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius + 0.167 * Radius / 2);
	//�����
	Ellipse(hdc, X - 0.416 * Radius + 0.167 * Radius, Y - 0.277 * Radius - 0.167 * Radius / 2, X - 0.416 * Radius, Y - 0.277 * Radius + 0.167 * Radius / 2);
	DeleteObject(Brush);
	//�������� ���
	HBRUSH BrushBlack = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, BrushBlack);
	Ellipse(hdc, X - 0.167 * Radius / 2, Y - 0.167 * Radius / 2, X + 0.167 * Radius / 2, Y + 0.167 * Radius / 2);
	DeleteObject(BrushBlack);
	//�������� ���
	PenBlack = CreatePen(PS_SOLID, 0.1 * Radius, RGB(0, 0, 0));
	SelectObject(hdc, PenBlack);
	MoveToEx(hdc, X - 0.33 * Radius, Y + 0.33 * Radius, 0);
	LineTo(hdc, X + 0.33 * Radius, Y + 0.33 * Radius);
	DeleteObject(PenBlack);
}
//������ ����
void Aircraft::Hide()
{
	Visible = false; //���� �� �����
	//����������� ������� ����� �����������
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);
	DeleteObject(Brush);

	//����������� ���������� ������
	HPEN PenWhite = CreatePen(PS_SOLID, 0.3 * Radius, RGB(255, 255, 255));
	SelectObject(hdc, PenWhite);
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);
	DeleteObject(PenWhite);
}

//�-�� ��� ������� ����������
//void Aircraft::MoveTo(int NewX, int NewY)
//{
//	Hide();//������ ������ �� ������� ����������
//	X = NewX; //������ ���������� ������
//	Y = NewY;
//	Show();//�������� ������ �� ����� �����������
//}

