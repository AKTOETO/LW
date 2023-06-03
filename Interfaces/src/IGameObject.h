#pragma once
#include "pch.h"

class IGameObject
{
public:

	// ������� ������ �������
	virtual void SetVisible() = 0;

	// ������� ������ �� �������
	virtual void SetInvisible() = 0;

	// ����������� ������ �� ������������ ����������
	virtual void SetPosition(Position) = 0;

	// ��������� ���������� ��������
	virtual void ProcessDraw() = 0;

	// ��������� ���������� ��������(������ ������)
	virtual void ProcessHide() = 0;

	// ��������� ���������� ��������(���������� ������)
	virtual void ProcessShow() = 0;
};

