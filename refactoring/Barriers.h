#pragma once
#include "pch.h"

// ��������� ����� �����������
class IBarrierPart
{
protected:
	// ������
	virtual void Rock() = 0;

	// ������� ������
	virtual void HugeRock() = 0;

	// �������������
	virtual void Rectangle() = 0;
};

// ����������� ������� ����� �����������
class ABCBaseBarrier :
	public IBarrierPart,
	public HitBox
{
protected:
	COLORREF m_color;	// ���� �����������
	HDC m_hdc;			// �������� �������

	// ��������� �����������
	virtual void Draw() = 0;

	// ����� �����������
	// ������
	virtual void Rock() override;

	// ������� ������
	virtual void HugeRock() override;

	// �������������
	virtual void Rectangle() override;

private:

	// ������ ������
	void Hide();

	// ���������� ������
	void Show();

public:
	// �����������
	ABCBaseBarrier(HDC _hdc, HitBox _box, COLORREF _color);

	// ��������� �����������
	void ProcessDraw();
};

// ������ �����������
class LightBarrier :
	public ABCBaseBarrier
{
public:
	// �����������
	LightBarrier(HDC _hdc);

	// ��������� �����������
	virtual void Draw() override;
};

// ������� �����������
class HugeBarrier :
	public ABCBaseBarrier
{
public:
	// �����������
	HugeBarrier(HDC _hdc);

	// ��������� �����������
	virtual void Draw() override;
};

// �������������
class RectBarrier :
	public ABCBaseBarrier
{
public:
	// �����������
	RectBarrier(HDC _hdc);

	// ��������� �����������
	virtual void Draw() override;
};
