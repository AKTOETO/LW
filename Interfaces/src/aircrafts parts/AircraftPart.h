#pragma once
#include "IAircraftPart.h"

// ����������� �����
class AircraftPart :
	public IAircraftPart,
	public HitBox
{
protected:

	//// ������, ������� ���� ����������
	//virtual void DrawModel() = 0;

	// �������� �������
	// (��������� ������ ����� �������� �������,
	// ����� ���������� � ������� ���-����)
	//const HDC& m_hdc;

private:

	//// ���� ��������� ������
	//COLORREF m_color;
	//
	//// ����� �� ������ ������
	//bool m_is_visisble;
	//
	//// ������� ������
	//void Hide();
	//
	//// ����������� ������
	//void Show();

public:

	AircraftPart(const HitBoxContext&);
	virtual ~AircraftPart();

	// �������� ����� ��������
	virtual void ProcessMove(Position) override;

	//// ����� �� ����� ��������
	//virtual void IsVisible(bool) override;

};
