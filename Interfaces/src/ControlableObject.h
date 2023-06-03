#pragma once

// ����� ������������ ��������� �����������
// �������� ������������ �������
enum class DIR
{
    STOP,   // ��� ��������
    UP,     // �����
    DOWN,   // ����
    LEFT,   // �����
    RIGHT   // ������
};

// ����� ������������ �������
class ControlableObject
{
private:
    // �������, ������������� ������
    void GenerateShift(float _time);

    DIR m_dir;      // ������� �����������
    float m_speed;  // �������� ������������
    bool m_controllable;

    // �������, ����������� ����� ���������������� �������
    // ����� �������� ��������� �� _shift
    virtual void ProcessMove(Position _shift) = 0;

public:

    // �����������
    ControlableObject(float _speed);

    // ������ ��������� ������ � ��������� �������
    virtual void ProcessLogic(float _time);

    // ����� ��������� ��� ���
    void SetControllable(bool);
};

