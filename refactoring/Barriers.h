#pragma once
#include "pch.h"

// ��������� ����� �����������
class IBarrierPart
{
protected:
	// ����� ���������
	virtual void Upgrade() = 0;

	// ����� ��������� ��������
	virtual void Downgrade() = 0;

	// ������
	virtual void Rock() = 0;
};

// ����������� ������� ����� �����������
class ABCBarrier :
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

	// ����� ���������
	virtual void Upgrade() override;

	// ����� ��������� ��������
	virtual void Downgrade() override;

private:

	// ������ ������
	void Hide();

	// ���������� ������
	void Show();

public:
	// �����������
	ABCBarrier(HDC _hdc, HitBox _box, COLORREF _color);

	// ��������� �����������
	void ProcessDraw();
};

// ������
class Mountain :
	public ABCBarrier
{
public:

	// �����������
	Mountain(HDC _hdc);

protected:

	// ��������� �����������
	virtual void Draw() override;
};

// ����� ���������
class UpgradeTower :
	public ABCBarrier
{
public:
	// �����������
	UpgradeTower(HDC _hdc);

protected:

	// ��������� �����������
	virtual void Draw() override;
};

// ����� ���������
class DowngradeTower :
	public ABCBarrier
{
public:
	// �����������
	DowngradeTower(HDC _hdc, HitBox _hb = { 400,300,80,100 });

protected:

	// ��������� �����������
	virtual void Draw() override;
};

// ����� ���������
class InherDowngradeTower :
	public DowngradeTower
{
public:
	// �����������
	InherDowngradeTower(HDC _hdc);

protected:

	virtual void Draw() override;
};