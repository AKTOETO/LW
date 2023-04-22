#pragma once

//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
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

	// ����������� �-�� (������� ����������)
	virtual void Show(); //�������� ����� �� ������
	virtual void Hide();//������ ����� 
	void Drag(); // �������� �������

	//�-�� ��� ������� ����������
	//void Show(); //�������� ����� �� ������
	//void Hide();//������ ����� 
	//void Drug(); // �������� �������

	// �������� 
	void MoveTo(int NewX, int NewY);//����������� ������

};//Point


/*-----------------------------------*/
/*          ����� Aircraft           */
/*-----------------------------------*/
class Aircraft :public Point
{
private:
	void Draw();

public:
	Aircraft(int InitX, int InitY); //�����������
	~Aircraft(); //����������

	// ����������� �-�� (������� ����������)
	void Show(); //�������� �� ������
	void Hide(); //������

	// ������� ����������
	//void MoveTo(int NewX, int NewY);
};