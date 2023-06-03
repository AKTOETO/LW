#pragma once
#include "../IGameObject.h"
#include "../barriers parts/IncludeBarrierParts.h"

class BaseBarrier :
    public IGameObject
{
protected:

	// ������ �����������
	std::vector<BaseBarrierPart*> m_parts;

public:
	// �����������
    BaseBarrier();

	virtual ~BaseBarrier();

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

