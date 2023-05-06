#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point.h"

// ��������� ���� ������ �������� �������
struct HitBox
{
	int m_width;	// ������
	int m_height;	// ������

	// ����������� �� ���������
	HitBox() : m_width(0), m_height(0) {};

	// ����������� � �����������
	HitBox(int _width, int _height)
		: m_width(_width), m_height(_height) {};

	// �������� �������� � �������� ������ �� �������� � ���������
	int GetShiftX(int _percents) { return (m_width * _percents / 100); }
	int GetShiftY(int _percents) { return (m_height * _percents / 100); };
};

// ����� �������� �������
class GameObject : public Point
{
protected:
	HitBox m_hitbox;	// ������� �������� �������
	HDC m_hdc;			// �������� �������
	COLORREF m_color;

	// ������� ��������� ������
	virtual void Draw();

public:
	// �����������, ����������� ���������� ������ �������� ����
	// �������� �������
	GameObject(int _x, int _y, const HDC& _hdc, HitBox _hb, COLORREF _color);
	virtual ~GameObject();

	// ����� ����������� ������ ��������� ������ � ��������� �������
	virtual void ProcessLogic(float _time);
	virtual void ProcessDraw();

	// ������ ��������� ������������� �������� �������
	const int& GetWidth() const;
	const int& GetHeight() const;

	// ������ ��������� ����������� ��� ������� �������
	virtual void Show() override;
	virtual void Hide() override;
};

#endif