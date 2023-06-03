#pragma once
#include "pch.h"

class DrawableObject
{
protected:

	// ������, ������� ���� ����������
	virtual void DrawModel() = 0;

	// �������� �������
	// (��������� ������ ����� �������� �������,
	// ����� ���������� � ������� ���-����)
	const HDC& m_hdc;

private:

	// ���� ��������� ������
	COLORREF m_color;

	// ����� �� ������ ������
	bool m_is_visisble;

	// ������� ������
	void Hide();

	// ����������� ������
	void Show();

public:

	DrawableObject(const DrawableObjectContext&);
	virtual ~DrawableObject();

	// ��������� ���������� ������� 
	virtual void ProcessDraw();

	// ��������� ����������� ������� (������)
	virtual void ProcessHide();

	// ��������� ����������� ������� (����������)
	virtual void ProcessShow();

	// ����� �� ������
	virtual void SetVisible(bool);
};

