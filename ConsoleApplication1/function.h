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
void new_motor(struct motor* motorishe)
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

//функция создания новых колес
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

void new_obchee(struct obchee* obchie)
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
		cout << "Добавление общей информации об автомобиле\n\nВведите модель автомобиля: ";
		gets_s(obchie->name);
		while (strlen(obchie->name) == 0)
		{
			printf("Неверно введена модель автомобиля, попробуйте еще: ");
			gets_s(obchie->name);
		}

		cout << "Введите тип привода (2WD/4WD): ";
		gets_s(obchie->tip_privoda);
		while (strlen(obchie->tip_privoda) == 0)
		{
			printf("Неверно введен тип привода, попробуйте еще: ");
			gets_s(obchie->tip_privoda);
		}

		cout << "Введите тип топлива (бензин/дизель/электро): ";
		gets_s(obchie->tip_topliva);
		while (strlen(obchie->tip_topliva) == 0)
		{
			printf("Неверно введен тип топлива, попробуйте еще: ");
			gets_s(obchie->tip_topliva);
		}

		cout << "Введите количество посадочных мест: ";
		while (scanf("%lf", &obchie->kolvo_mest) != 1)
		{
			printf("Неверно введенно значение количества посадочных мест, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите время разгона до 100км/ч: ";
		while (scanf("%lf", &obchie->razgon_do_100) != 1)
		{
			printf("Неверно введенно значение разгона до 100км/ч, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите массу автомобиля: ";
		while (scanf("%lf", &obchie->massa) != 1)
		{
			printf("Неверно введенно значение массы, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите объем бензобака в литрах: ";
		while (scanf("%lf", &obchie->obem_benzobaka) != 1)
		{
			printf("Неверно введенно значение объема бензобака, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
	else
	{
		obchie->kolvo_mest = 5;
		obchie->massa = 1500;
		strcpy(obchie->name, "Subaru");
		obchie->obem_benzobaka = 50;
		obchie->razgon_do_100 = 10;
		strcpy(obchie->tip_privoda, "2WD");
		strcpy(obchie->tip_topliva, "Бензин");
	}
}

void new_korobka(struct korobka_peredach* korobka_peredach1)
{
	system("cls");
	cout << "Добавление информации о коробке передач автомобиля\n\nВведите тип коробки передач (АКПП/МКПП): ";
	gets_s(korobka_peredach1->tip_korobki);
	while (strlen(korobka_peredach1->tip_korobki) == 0)
	{
		printf("Неверно введена модель автомобиля, попробуйте еще: ");
		gets_s(korobka_peredach1->tip_korobki);
	}

	cout << "Введите количество передач коробки: ";
	while (scanf("%lf", &korobka_peredach1->kolvo_peredach) != 1)
	{
		printf("Неверно введено значение количества передач, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

}
//функция создания нового автомобиля
void new_car(struct avto* avtomobil)
{
	new_motor(&avtomobil->har2);
	new_obchee(&avtomobil->har5);
	new_korobka(&avtomobil->har4);
	new_kolesa(&avtomobil->har3);
}

//функция просмотра комплектующих и автомобиля
void prosmotr_agr(struct motor* motorishe, struct kolesa* koleso, struct obchee* obchie, struct korobka_peredach* korobka_peredach1, struct avto* avtomobil)
{
	int menu;
	system("cls");
	cout << "1) Просмотр двигателей\n2) Просмотр колес\n3) Просмотр общих характеристик\n4) Просмотр коробок передач\n5) Просмотр авто\n0) Возврат в меню";
	menu = _getch();
	if (menu == '1')
	{
		cout << "\n\nИНФОРАЦИЯ О ДВИГАТЕЛЕ:\nМаркировка двигателя: " << motorishe->name;
		cout << "\nРабочий объем: " << motorishe->rab_obem;
		cout << "\nМощность (л.с.): " << motorishe->koni;
		cout << "\nСредний расход на 100км: " << motorishe->rasxod;
		cout << "\nКоличество цилиндров: " << motorishe->kol_vo_cilindr;
		cout << "\nКоличество клапанов на 1 цилиндр: " << motorishe->klapan;
	}
	else if (menu == '2')
	{
		cout << "\n\nИНФОРМАЦИЯ О КОЛЕСАХ\nШирина колеса: " << koleso->shirina;
		cout << "\nДиаметр колеса: " << koleso->diametr;
		cout << "\nВысота колеса: " << koleso->visota;
		cout << "\nТип диска: " << koleso->tip_diska;
	}
	else if (menu == '3')
	{
		cout << "\n\nОБЩАЯ ИНФОРМАЦИЯ:\nМодель: " << obchie->name;
		cout << "\nТип привода: " << obchie->tip_privoda;
		cout << "\nТип топлива: " << obchie->tip_topliva;
		cout << "\nКоличество посадочных мест: " << obchie->kolvo_mest;
		cout << "\nВремя разгона до 100км/ч: " << obchie->razgon_do_100;
		cout << "\nОбъем бензобака: " << obchie->obem_benzobaka;
		cout << "\nМасса: " << obchie->massa;
	}
	else if (menu == '4')
	{
		cout << "\n\nИНФОРМАЦИЯ О КОРОБКЕ ПЕРЕКЛЮЧЕНИЯ ПЕРЕДАЧ\nТип коробки переключения передач: " << korobka_peredach1->tip_korobki;
		cout << "\nКоличество передач коробки: " << korobka_peredach1->kolvo_peredach;
	}
	cout << "Для возврата в меню нажмите любую клавишу";
	_getch();
}

void gl_menu()
{
	struct motor motorishe;
	struct kolesa koleso;
	struct obchee obchie;
	struct korobka_peredach korobka_peredach1;
	struct avto avtomobil;
	int menu;
	do
	{

		system("cls");
		cout << "\n1) Новый двигатель\n2) Новые колеса\n3) Новые общие характеристики\n4) Новая коробка передач\n5) Новый авто\n6) Просмот агрегатов и авто\n\nESC - выход";
		menu = _getch();
		if (menu == '1')
		{
			new_motor(&motorishe);
		}
		else if (menu == '2')
		{
			new_kolesa(&koleso);
		}
		else if (menu == '3')
		{
			new_obchee(&obchie);
		}
		else if (menu == '4')
		{
			new_korobka(&korobka_peredach1);
		}
		else if (menu == '5')
		{
			new_car(&avtomobil);
		}
		else if (menu == '6')
		{
			prosmotr_agr(&motorishe, &koleso, &obchie, &korobka_peredach1, &avtomobil);
		}
	} while (menu != 27);

}
