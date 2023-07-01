#pragma once
#include "pch.h"

// ����������� ��������
enum class DIR
{
    STOP,
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class ABCMoveableObject :
    public HitBox
{
protected:

    float m_speed;      // �������� �������
    COLORREF m_color;	// ���� ��������	
    HDC m_hdc;			// �������� �������
    Position m_shift;   // ����� �������
    DIR m_dir;          // ����������� ��������

    // ��������� �������� �������
    virtual void Draw() = 0;

    // �������� ������ �������
    virtual void CalcShiftPos() = 0;

public:
    ABCMoveableObject(HDC _hdc, HitBox _box, COLORREF _color, float _speed);
    ~ABCMoveableObject();

    // ����� ����������� ������� �� ������������ ����������
    void Reposition(Position _pos);

    // ����� ������� �������
    void Hide();

    // ����� ����������� �������
    void Show();

    // ��������� �������������� �������
    void ProcessDraw();

    // �������� ������� ����������� ��������
    const DIR& GetDir() const;
};

