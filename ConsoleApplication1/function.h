#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;

//фукнция создания нового двигателя
void new_motor(struct motor *motorishe)
{
	int menu;
	do
	{
		system("cls");
		cout << "1) Ввод собственных данных о двигателе\n2)Создание по конструктору";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{
		cout << "Введите маркировку двигателя: ";
		gets_s(motorishe->name);
		while (strlen(motorishe->name) == 0)
		{
			printf("Неверно введена маркировка двигателя, попробуйте еще: ");
			gets_s(motorishe->name);
		}
		cout << "Введите рабочий объем двигателя в литрах: ";
		while (scanf("%lf", &motorishe->rab_obem) != 1)
		{
			printf("Неверно введено значение объема двигателя, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите количество лошадинных сил: ";
		while (scanf("%lf", &motorishe->koni) != 1)
		{
			printf("Неверно введено значение количества лошадиных сил, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите средний расход топлива на 100км в литрах: ";
		while (scanf("%lf", &motorishe->rasxod) != 1)
		{
			printf("Неверно введено значение расхода на 100км, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите количество цилиндров: ";
		while (scanf("%lf", &motorishe->kol_vo_cilindr) != 1)
		{
			printf("Неверно введено значение количества цилиндров, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите количество клапанов на один цилиндр: ";
		while (scanf("%lf", &motorishe->klapan) != 1)
		{
			printf("Неверно введено значение количества клапанов, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
	else
	{
		strcpy(motorishe->name, "Stok");
		motorishe->rasxod = 10;
		motorishe->rab_obem = 2;
		motorishe->koni = 100;
		motorishe->kol_vo_cilindr = 4;
		motorishe->klapan = 4;

	}
	
}
void new_kolesa(struct kolesa* koleso)
{
	int menu;
	do
	{
		system("cls");
		cout << "1) Ввод собственных данных о колесах\n2)Создание по конструктору";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{
		system("cls");
		cout << "Добавление информации о колесах автомобиля\n\nВведите ширину колеса: ";
		while (scanf("%lf", &koleso->shirina) != 1)
		{
			printf("Неверно введено значение ширины колеса, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите высоту колеса: ";
		while (scanf("%lf", &koleso->visota) != 1)
		{
			printf("Неверно введено значение высоты колеса, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите диаметр колеса в дюймах: ";
		while (scanf("%lf", &koleso->diametr) != 1)
		{
			printf("Неверно введено значение диаметра колеса, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите тип колесного диска (штамповка/литье/ковка): ";
		gets_s(koleso->tip_diska);
		while (strlen(koleso->tip_diska) == 0)
		{
			printf("Неверно введен тип колесного диска, попробуйте еще: ");
			gets_s(koleso->tip_diska);
		}
	}
	else
	{
		strcpy(koleso->tip_diska, "Штамповка");
		koleso->visota = 60;
		koleso->shirina = 190;
		koleso->diametr = 15;
	}
}

void prosmotr_agr()
{
	int menu;
	cout << "1) Просмотр двигателей\n2) Просмотр колес\n3) Просмотр общих характеристик\n4) Просмотр коробок передач\n5) Просмотр авто\n0) Возврат в меню";
	menu = _getch();
	if (menu == '1');
}

void gl_menu()
{
	struct motor motorishe;
	struct kolesa koleso;
	int menu;
	cout << "\n1) Новый двигатель\n2) Новые колеса\n3) Новые общие характеристики\n4) Новая коробка передач\n5) Новый авто\n6) Просмот агрегатов и авто";
	menu = _getch();
	if (menu == '1')
	{
		new_motor(&motorishe);
	}
	else if (menu == '2')
	{
		new_kolesa(&koleso);
	}
	
	else if (menu == '6')
	{
		prosmotr_agr();
	}

}
