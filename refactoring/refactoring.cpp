﻿/**************************************************************************
*               КАФЕДРА №304 2 КУРС ООП ЛАБОРАТОРНАЯ РАБОТА               *
***************************************************************************
*Project type :Win64 Console Application                                  *
*Project name :LW.sln					         			              *
*File name    :LW.cpp                                                     *
*Language     :C++                                                        *
*Programmers  :Плоцкий Богдан Андреевич     М3О-211Б-21      		      *
*Modified By  :Плоцкий Богдан Андреевич     М3О-211Б-21                   *
*Created      :1.05.2023                                                  *
*Last revision:20.05.2023                                                 *
*Comments	  :Динамический полиморфизм                                   *
**************************************************************************/

#include "Aircrafts.h"
#include "Barriers.h"

using namespace std;           // Пространство имен std

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//
//HDC hdc;// Объявим контекст устройства
//// Контекст устройства по сути это структура,
//// содержащая описание видеокарты на вашем компьютере
//// и всех необходимых графических элементов

/*---------------------------------------------------------------------*/
/*               П Р О Т О Т И П Ы    Ф У Н К Ц И Й                    */
/*---------------------------------------------------------------------*/
HWND GetConcolWindow(); //указатель на консольное окно
bool Collision(const ABCBaseAircraft& _air, const ABCBaseBarrier& _bar);

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
int main()
{
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		HDC hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			// массив указателей на самолеты
			// тут будет 5 элементов
			std::vector<ABCBaseAircraft*> aircrafts =
			{
				new Aircraft(hdc),
				new BrokenAircraft(hdc),
				new FuselageAircraft(hdc),
			};

			// массив указателей на препятствия
			// тут будет 3 элемента
			std::vector<ABCBaseBarrier*> bars =
			{
				new LightBarrier(hdc),
				new HugeBarrier(hdc),
				new RectBarrier(hdc),
			};

			// матрица пересечений
			// collis[i][j] = t
			// i - номер самолета из массива aircrafts
			// j - номер препятствия из массива bars
			// t - номер полученного после пересечения самолета из массива aircrafts
			std::vector<std::vector<int>> collis =
			{
				{0, 1, 2},
				{2, 1, 0},
				{1, 0, 2},
			};

			// есть ли пересачение самолета с текущим препятствием
			std::vector<bool> is_collision(bars.size(), 0);
			// было ли пересачение самолета с текущим препятствием
			std::vector<bool> was_changed(bars.size(), 0);

			// указатель на текущий самолет
			int cur_aircraft_index = 0;
			ABCBaseAircraft* cur_air = aircrafts[cur_aircraft_index];

			// главный цикл программы
			while (!KEY_DOWN(K_EXIT))
			{
				// отрисовка всех препятствий
				std::for_each(bars.begin(), bars.end(), [](const auto& _bar) {_bar->ProcessDraw(); });

				// Отрисовка
				cur_air->ProcessDraw();

				// обработка столкновений
				for (int j = 0; j < collis[0].size(); j++)
				{
					// если самолет и препятствие пересеклось
					if (Collision(*cur_air, *bars[j]))
					{
						is_collision[j] = 1;
					}
					else
					{
						is_collision[j] = 0;
						was_changed[j] = 0;
					}

					// если сейчас есть пересечение, а шаг назад его не было
					if (is_collision[j] && !was_changed[j])
					{
						// новый индекс самолета
						int new_aircraft = collis[cur_aircraft_index][j];

						// переношу конечный самолет в текущие координаты
						aircrafts[new_aircraft]->SetX(cur_air->GetX());
						aircrafts[new_aircraft]->SetY(cur_air->GetY());

						// выключаю видимость текущего самолета
						// и включаю видимость конечного
						cur_air->Hide();
						aircrafts[new_aircraft]->Show();

						// присваиваю текущий самолет текущему указателю на самолет
						cur_air = aircrafts[new_aircraft];

						// меняю текущий номер самолета
						cur_aircraft_index = new_aircraft;

						// пересечение случилось
						was_changed[j] = 1;
					}
				}
				Sleep(10);
			}

		}//end if
	}//end if
	return 0;
}//end main()


/*---------------------------------------------------------------------*/
/*               Р Е А Л И З А Ц И Я   Ф У Н К Ц И Й                   */
/*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*  Создать консольное окно  */
/*---------------------------*/
HWND GetConcolWindow()
{
	char str[128];
	// char title[128]="xxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";	//новая версия Windows
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // получить заголовок окна
	SetConsoleTitle(title);						// установить новый заголовок окна
	Sleep(100);									// ждем смены заголовка окна (100 мс);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);// определяем дескриптор окна
	SetConsoleTitle((LPWSTR)str);				//возвращаем прежний заголовок

	return hwnd;//вернуть дескриптор окна
}
//end GetConcolWindow()

// просчет колизии
bool Collision(const ABCBaseAircraft& _air, const ABCBaseBarrier& _bar)
{
	int r1 = _air.GetX() + _air.GetWidth();
	int b1 = _air.GetY() + _air.GetHeight();
	int r2 = _bar.GetX() + _bar.GetWidth();
	int b2 = _bar.GetY() + _bar.GetHeight();
	return (_air.GetX() < r2) && (_bar.GetX() < r1) && (_air.GetY() < b2) && (_bar.GetY() < b1);
}