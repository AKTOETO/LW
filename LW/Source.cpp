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
Point::Point(int InitX, int InitY)
	: Location(InitX, InitY)
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

/*-------------------*/
/*       Point       */
/*-------------------*/

//������ ����� �� ������
void Point::Hide()
{
	Visible = false;
	SetPixel(hdc, X, Y, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));//������ ����� ������������ ������
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));//������ ����� ������������ ������

}

// ����������� �� ��������
void Point::Drag()
{
	// ���� �� ������ Q
	while (!KEY_DOWN(81))
	{
		// A - ����
		if (KEY_DOWN(65)) MoveTo(X - 10, Y);
		// W - �����
		else if (KEY_DOWN(87)) MoveTo(X, Y - 10);
		// D - ������
		else if (KEY_DOWN(68)) MoveTo(X + 10, Y);
		// S - ����
		else if (KEY_DOWN(83)) MoveTo(X, Y + 10);
		Sleep(100);
	}
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
/*             Aircraft              */
/*-----------------------------------*/
void Aircraft::Draw()
{
	// ������
	MoveToEx(hdc, X, Y, NULL);
	LineTo(hdc, X + 20, Y);
	LineTo(hdc, X + 25, Y + 10);
	LineTo(hdc, X + 70, Y + 10);
	LineTo(hdc, X + 80, Y + 20);
	LineTo(hdc, X + 70, Y + 30);
	LineTo(hdc, X + 5, Y + 30);
	LineTo(hdc, X, Y);

	//�����
	MoveToEx(hdc, X + 25, Y + 20, NULL);
	LineTo(hdc, X + 20, Y + 50);
	LineTo(hdc, X + 30, Y + 50);
	LineTo(hdc, X + 45, Y + 20);
}

//�����������
Aircraft::Aircraft(int InitX, int InitY)
	:Point(InitX, InitY)
{
}
//����������
Aircraft::~Aircraft()
{
};


//�������� �� ������
void Aircraft::Show()
{
	Visible = true;
	//������� ���� � ���� ����
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	//������ ���� �������� 
	SelectObject(hdc, PenBlack);
	Draw();

	DeleteObject(PenBlack);
}

//������
void Aircraft::Hide()
{
	Visible = false; // �� �����
	//����������� ������� ����� �����������
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	//������ ���� �������� 
	SelectObject(hdc, PenBlack);
	Draw();

	DeleteObject(PenBlack);
}

