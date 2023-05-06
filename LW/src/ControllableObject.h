#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H

#include "GameObject.h"

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

class ControllableObject :
    public GameObject
{
private:
    // �������, ������������� ������
    void Move(float _time);

protected:
    DIR m_dir;
    float m_speed;
    bool m_is_controllable;

    // ������� ��������� ������
    //virtual void Draw() override;

public:

    // ����������� � ����������
    ControllableObject(
        int _x, int _y, const HDC& _hdc, float _speed = 10, HitBox _hb = {10,10}, COLORREF _color = RED, bool is_mooveable = 1
    );
    virtual ~ControllableObject();

    // ������ ��������� ������ � ��������� �������
    virtual void ProcessLogic(float _time) override;

    // ���������� ���������: ��������� ��� ���
    void SetControllable(bool);
};

#endif //!CONTROLLABLEOBJECT_H