#pragma once
#include "aircrafts/Aircraft.h"
#include "barriers/Mountain.h"

HWND GetConcolWindow(); //��������� �� ���������� ����

int main(int argc, char* argv[])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//������� ���������� ����������� ����
	HWND hwnd = GetConcolWindow();
	DWORD l;
	COORD point;
	point.X = 0; point.Y = 0;
	
	//���� ���������� ����������
	if (hwnd != NULL)
	{
		HDC hdc = GetWindowDC(hwnd);
		//���� �������� ���������� - ����� ��������
		if (hdc != 0)
		{
			HdcPos cnt(hdc, { 100,100 });
			Aircraft ar(cnt);
			ar.SetVisible();

			cnt.m_pos.SetPos({ 200,200 });
			Mountain mn(cnt);
			
			while (1)
			{
				ar.ProcessHide();
				ar.ProcessLogic(1);	
				ar.ProcessShow();

				mn.ProcessDraw();

				Sleep(10);
			}
		}
	}

	return 0;
}

HWND GetConcolWindow()
{
	char str[128];
	// char title[128]="xxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";	//����� ������ Windows
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // �������� ��������� ����
	SetConsoleTitle(title);						// ���������� ����� ��������� ����
	Sleep(100);									// ���� ����� ��������� ���� (100 ��);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);// ���������� ���������� ����
	SetConsoleTitle((LPWSTR)str);				//���������� ������� ���������

	return hwnd;//������� ���������� ����
}