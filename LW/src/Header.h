#pragma once
/*-----------------------------------------------------------------*/
/*               � � � � � � � � � �   � � � � � � �               */
/*-----------------------------------------------------------------*/

/*-----------------------------------*/
/*          ����� Location           */
/*-----------------------------------*/
//������� �����
class Location
{
protected:
	int X;
	int Y;
public:
	Location(int InitX, int InitY); //�����������
	~Location(); //����������
	int GetX(); //�������� �������� ���� X READ
	int GetY(); //�������� �������� ���� Y 
	void SetX(int NewX)  //�������� �������� ���� X WRITE
	{ 
		X = NewX;
	};
	void SetY(int NewY) //�������� �������� ���� Y
	{ 
		Y = NewY;
	}; 
};//Location

/*-----------------------------------*/
/*            ����� Point            */
/*-----------------------------------*/
//����������� �����
class Point : public Location
{
protected:
	bool Visible; //��������� ����� ��� ���
public:
	Point(int InitX, int InitY); //�����������
	~Point(); //����������
	bool IsVisisble(); //������ ��� ���������� �����
	void SetVisible(bool NewVisible) { Visible = NewVisible; }; //�������� ����������

	//����������� �-�� (������� ����������)
	virtual void Show(); //�������� ����� �� ������
	virtual void Hide();//������ ����� 

	//�-�� ��� ������� ����������
	//void Show(); //�������� ����� �� ������
	//void Hide();//������ ����� 
	void MoveTo(int NewX, int NewY);//����������� ������
};//Point
/*-----------------------------------*/
/*          ����� Aircraft           */
/*-----------------------------------*/
class Aircraft :public Point
{
protected:
	int Radius; //������ ����
	int EyeColor; //���� ���� (0 - �������, 1 - ����������, 2 - ������, 3 - �������)
public:
	Aircraft(int InitX, int InitY, int InitRadius, int InitEyeC); //�����������
	~Aircraft(); //����������
	void Show(); //�������� ���� �� ������
	void Hide(); //������ ����

	//�-�� ��� ������� ����������
	/*void MoveTo(int NewX, int NewY);*/
};
//���� ����
enum Color
{
	Red, Brown, Black, Green
};