#pragma once
#include "../pch.h"

// ��������� ����� ��������
class IAircraftPart
{
public:
	// �������� ����� ��������
	virtual void ProcessMove(Position) = 0;

	// ����� �� ���� ��������
	//virtual void IsVisible(bool) = 0;
};
