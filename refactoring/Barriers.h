#pragma once
#include "UncontrollableObject.h"

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
	public ABCUncontrollableObject
{
protected:

	// ����� �����������
	// ������
	virtual void Rock() override;

	// ����� ���������
	virtual void Upgrade() override;

	// ����� ��������� ��������
	virtual void Downgrade() override;

public:
	// �����������
	ABCBarrier(HDC _hdc, HitBox _box, COLORREF _color);
};

// ������
class Mountain :
	public ABCBarrier
{
public:

	// �����������
	Mountain(HDC _hdc);

	// ����������� � �������� �������
	Mountain(HDC _hdc, Position _pos);

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
	DowngradeTower(HDC _hdc);

protected:

	// ��������� �����������
	virtual void Draw() override;
};
