#ifndef I_GAMEOBJECT_H
#define I_GAMEOBJECT_H

// ��������� �������� �������
class IGameObject
{
public:
	// ����� ����������� ����� ��������� ������ 
	virtual void ProcessLogic(float _time) = 0;
	// ����� ����������� ����� ��������� �������
	virtual void ProcessDraw() = 0;

};

#endif //!I_GAMEOBJECT_H