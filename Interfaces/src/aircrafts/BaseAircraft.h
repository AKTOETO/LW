#pragma once
#include "../ControlableObject.h"
#include "../IGameObject.h"
#include "../aircrafts parts/IncludeParts.h"

class BaseAircraft :
	public IGameObject,
	public ControlableObject
{
private:
	// ����� �������
	virtual void ProcessMove(Position _shift) override;

protected:

	// ������ ������ ��������
	std::vector<BaseAircraftPart*> m_aircraft_parts;

public:
	// ������ ������� ������������
	BaseAircraft() = delete;

	// �����������
	BaseAircraft(float _speed);

	virtual ~BaseAircraft();

	// �������� ������ ��������� �������� �������
	// (����� ��� ��������� ������������)
	std::list<HitBox> GetHitBoxes() const;

	// ������� ������ �������
	virtual void SetVisible() override;

	// ������� ������ �� �������
	virtual void SetInvisible() override;

	// ����������� ������ �� ������������ ����������
	virtual void SetPosition(Position) override;

	// ���������
	virtual void ProcessDraw() override;

	// ��������� ���������� ��������(������ ������)
	virtual void ProcessHide() override;

	// ��������� ���������� ��������(���������� ������)
	virtual void ProcessShow() override;
};

