#pragma once
#include "aircrafts/Aircraft.h"
#include "aircrafts/SlowAircraft.h"
#include "aircrafts/WindowAircraft.h"
#include "barriers/Mountain.h"

HWND GetConcolWindow(); //��������� �� ���������� ����

bool CollisionHitbox(const HitBox& _first, const HitBox& _second);
bool CollisionGameObjects(std::list<HitBox> _moveable, std::list<HitBox> _barrier);

int main(int argc, char* argv[])
{
	//������� ���������� ����������� ����
	HWND hwnd = GetConcolWindow();

	//���� ���������� ����������
	if (hwnd != NULL)
	{
		HDC hdc = GetWindowDC(hwnd);
		//���� �������� ���������� - ����� ��������
		if (hdc != 0)
		{
			// ������ ���������� �� ��������
			// ��� ����� 5 ���������
			std::vector<BaseAircraft*> aircrafts =
			{
				new Aircraft({hdc, {100,100}}),
				new SlowAircraft({hdc, {100,150}}),
				new WindowAircraft({hdc, {0,0}}),
				//new CargoAircraft(100, 100, hdc, 7, {100,100}, GREEN),           
				//new DeadAircraft(100, 100, hdc, 0, {150,150}, BLACK),            
				//new RocketCarrierAircraft(100, 100, hdc, 10, {150,150}, YELLOW), 
			};

			// ������ ���������� �� �����������
			// ��� ����� 3 ��������
			std::vector<BaseBarrier*> bars =
			{
				new Mountain({hdc, {300,150}}),  // Rock
				new Mountain({hdc, {350,50}}),  // Rock
				new Mountain({hdc, {500,250}}),  // Rock
				//new Cloud(300, 300, hdc, { 20,70 }, BLUE),  // Clouds			
				//new RocketStation(500, 400, hdc, { 45,150 }, RED)     // RocketStation
			};

			// ������� �����������
			// collis[i][j] = t
			// i - ����� �������� �� ������� aircrafts
			// j - ����� ����������� �� ������� bars
			// t - ����� ����������� ����� ����������� �������� �� ������� aircrafts
			std::vector<std::vector<int>> collis =
			{
				{1, 2, 1},
				{0, 2, 0},
				{2, 0, 2},
				//{2, 0, 3},
			};

			// ���� �� ����������� �������� � ������� ������������
			std::vector<bool> is_collision(bars.size(), 0);
			// ���� �� ����������� �������� � ������� ������������
			std::vector<bool> was_changed(bars.size(), 0);

			// ��������� �� ������� �������
			int cur_aircraft_index = 0;
			BaseAircraft* cur_air = aircrafts[cur_aircraft_index];
			cur_air->SetVisible();

			// ������� ���� ���������
			while (!KEY_DOWN(K_EXIT))
			{
				// ��������� ���� �����������
				std::for_each(bars.begin(), bars.end(), [](const auto& _bar) {_bar->ProcessDraw(); });

				// ������� ������ � ��������� ��������
				cur_air->ProcessHide();
				cur_air->ProcessLogic(1);
				cur_air->ProcessShow();

				// ��������� ������������
				for (int j = 0; j < collis[0].size(); j++)
				{
					// ���� ������� � ����������� �����������
					if (CollisionGameObjects(cur_air->GetHitBoxes(), bars[j]->GetHitBoxes()))
					{
						is_collision[j] = 1;
					}
					else
					{
						is_collision[j] = 0;
						was_changed[j] = 0;
					}

					// ���� ������ ���� �����������, � ��� ����� ��� �� ����
					if (is_collision[j] && !was_changed[j])
					{
						// ����� ������ ��������
						int new_aircraft = collis[cur_aircraft_index][j];

						// �������� �������� ������� � ������� ����������
						aircrafts[new_aircraft]->SetPosition((cur_air->GetHitBoxes().begin())->GetPos());
						//aircrafts[new_aircraft]->SetX(cur_air->GetX());
						//aircrafts[new_aircraft]->SetY(cur_air->GetY());

						// �������� ��������� �������� ��������
						// � ������� ��������� ���������
						cur_air->SetInvisible();
						cur_air->ProcessHide();
						aircrafts[new_aircraft]->SetVisible();
						//cur_air->Hide();
						//aircrafts[new_aircraft]->Show();
						//std::cout << new_aircraft << std::endl;
						// ���������� ������� ������� �������� ��������� �� �������
						cur_air = aircrafts[new_aircraft];
						cur_air->ProcessShow();

						// ����� ������� ����� ��������
						cur_aircraft_index = new_aircraft;

						// ����������� ���������
						was_changed[j] = 1;
					}
				}
				Sleep(10);
			}
		}
	}

	return 0;
}

HWND GetConcolWindow()
{
	char str[128];
	// char title[128]="xxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";	//����� ������ Windows
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // �������� ��������� ����
	SetConsoleTitle(title);						// ���������� ����� ��������� ����
	Sleep(100);									// ���� ����� ��������� ���� (100 ��);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);// ���������� ���������� ����
	SetConsoleTitle((LPWSTR)str);				//���������� ������� ���������

	return hwnd;//������� ���������� ����
}

bool CollisionHitbox(const HitBox& _first, const HitBox& _second)
{
	int r1 = _first.GetX() + _first.GetWidth();
	int b1 = _first.GetY() + _first.GetHeight();
	int r2 = _second.GetX() + _second.GetWidth();
	int b2 = _second.GetY() + _second.GetHeight();
	return
		(_first.GetX() < r2) && (_second.GetX() < r1) &&
		(_first.GetY() < b2) && (_second.GetY() < b1);
}

bool CollisionGameObjects(std::list<HitBox> _moveable, std::list<HitBox> _barrier)
{
	for (auto& f : _moveable)
	{
		for (auto& s : _barrier)
		{
			if (CollisionHitbox(f, s))
				return true;
		}
	}
	return false;
}
