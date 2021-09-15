#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include <iostream>
#include "demo.h"
#include "struct.h"

using namespace std;

//фукнция создания нового двигателя
void new_motor( motor* motorishe)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) Ввод собственных данных о двигателе\n2) Создание по конструктору";
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
		while (scanf("%lf", &motorishe->rab_obem) != 1 || motorishe->rab_obem < 0)
		{
			printf("Неверно введено значение объема двигателя, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите количество лошадинных сил: ";
		while (scanf("%lf", &motorishe->koni) != 1 || motorishe->koni < 0)
		{
			printf("Неверно введено значение количества лошадиных сил, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите средний расход топлива на 100км в литрах: ";
		while (scanf("%lf", &motorishe->rasxod) != 1 || motorishe->rasxod < 0)
		{
			printf("Неверно введено значение расхода на 100км, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите количество цилиндров: ";
		while (scanf("%lf", &motorishe->kol_vo_cilindr) != 1 || motorishe->kol_vo_cilindr < 0)
		{
			printf("Неверно введено значение количества цилиндров, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите количество клапанов на один цилиндр: ";
		while (scanf("%lf", &motorishe->klapan) != 1 || motorishe->klapan < 0)
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
void new_kolesa( kolesa* koleso)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) Ввод собственных данных о колесах\n2) Создание по конструктору";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{
		system("cls");
		cout << "Добавление информации о колесах автомобиля\n\nВведите ширину колеса: ";
		while (scanf("%lf", &koleso->shirina) != 1 || koleso->shirina < 0)
		{
			printf("Неверно введено значение ширины колеса, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите высоту колеса: ";
		while (scanf("%lf", &koleso->visota) != 1 || koleso->visota < 0)
		{
			printf("Неверно введено значение высоты колеса, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите диаметр колеса в дюймах: ";
		while (scanf("%lf", &koleso->diametr) != 1 || koleso->diametr < 0)
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

//функция создания общих характеристик
void new_obchee( obchee* obchie)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) Ввод собственных данных об общем\n2) Создание по конструктору";
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
		while (scanf("%lf", &obchie->kolvo_mest) != 1 || obchie->kolvo_mest < 0)
		{
			printf("Неверно введенно значение количества посадочных мест, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите время разгона до 100км/ч: ";
		while (scanf("%lf", &obchie->razgon_do_100) != 1 || obchie->razgon_do_100 < 0)
		{
			printf("Неверно введенно значение разгона до 100км/ч, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите массу автомобиля: ";
		while (scanf("%lf", &obchie->massa) != 1 || obchie->massa < 0)
		{
			printf("Неверно введенно значение массы, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите объем бензобака в литрах: ";
		while (scanf("%lf", &obchie->obem_benzobaka) != 1 || obchie->obem_benzobaka < 0 )
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

//функция создания новой коробки передач
void new_korobka( korobka_peredach* korobka_peredach1)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) Ввод собственных данных о коробке передач\n2) Создание по конструктору";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
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
		while (scanf("%lf", &korobka_peredach1->kolvo_peredach) != 1 || korobka_peredach1->kolvo_peredach < 0)
		{
			printf("Неверно введено значение количества передач, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
	else
	{
		strcpy(korobka_peredach1->tip_korobki, "АКПП");
		korobka_peredach1->kolvo_peredach = 5;
	}
}

//функция создания нового водителя
void new_vod(voditel* vod, int red)
{
	int menu = '1';
	if (red == 0)
	{
		do
		{
			system("cls");
			cout << "1) Ввод собственных данных о водителе\n2) Создание по конструктору";
			menu = _getch();
		} while (menu != '1' && menu != '2');
	}
	system("cls");
	if (menu == '1')
	{
		if (red == 1 || red == 0)
		{
			cout << "Введите ФИО водителя : ";
			gets_s(vod->name);
			while (strlen(vod->name) == 0)
			{
				printf("Неверно введен ФИО водителя, попробуйте еще: ");
				gets_s(vod->name);
			}
		}
		if (red == 2 || red == 0)
		{
			cout << "Введите возраст: ";
			while (scanf("%lf", &vod->age) != 1)
			{
				printf("Неверно введен возраст водителя, попробуйте еще: ");
				while (getchar() != '\n');
			}
			while (getchar() != '\n');
		}
		if (red == 3 || red == 0)
		{
			cout << "Введите пол водителя (М/Ж): ";
			gets_s(vod->pol);
			while (strlen(vod->pol) == 0)
			{
				printf("Неверно введен пол водителя, попробуйте еще: ");
				gets_s(vod->pol);
			}
		}
		
		if (red == 4 || red == 0)
		{
			cout << "Введите статус Covid-19 (переболел/привит/неизвестно): ";
			gets_s(vod->covid_19);
			while (strlen(vod->covid_19) == 0)
			{
				printf("Неверно введен статус COVID-19, попробуйте еще: ");
				gets_s(vod->covid_19);
			}
		}
		
		if (red == 5 || red == 0)
		{
			cout << "Введите стаж водителя: ";
			while (scanf("%lf", &vod->stag) != 1)
			{
				printf("Неверно введен стаж водителя, попробуйте еще: ");
				while (getchar() != '\n');
			}
			while (getchar() != '\n');
		}
	}
	else
	{
		strcpy(vod->name, "Иванов И.И.");
		strcpy(vod->covid_19, "Неизвестно");
		strcpy(vod->pol, "М");
		vod->age = 23;
		vod->stag = 1;
	}
}

//функция создания нового автомобиля
void new_car( avto* avtomobil)
{
	new_motor(&avtomobil->har2);
	new_obchee(&avtomobil->har5);
	new_korobka(&avtomobil->har4);
	new_kolesa(&avtomobil->har3);
}

//функция просмотра информации о двигателе
void prosmotr_motor(motor* motorishe)
{
	if (motorishe->rasxod >= 0)
	{
		cout << "\n\nИНФОРАЦИЯ О ДВИГАТЕЛЕ:\nМаркировка двигателя: " << motorishe->name;
		cout << "\nРабочий объем: " << motorishe->rab_obem;
		cout << "\nМощность (л.с.): " << motorishe->koni;
		cout << "\nСредний расход на 100км: " << motorishe->rasxod;
		cout << "\nКоличество цилиндров: " << motorishe->kol_vo_cilindr;
		cout << "\nКоличество клапанов на 1 цилиндр: " << motorishe->klapan;
	}
	else
	{
		cout << "Информация о двигателе отсутствует";
	}
}

//функция просмотра информации о колесах
void prosmotr_kolesa(kolesa *koleso)
{
	if (koleso->visota >= 0)
	{
		cout << "\n\nИНФОРМАЦИЯ О КОЛЕСАХ\nШирина колеса: " << koleso->shirina;
		cout << "\nДиаметр колеса: " << koleso->diametr;
		cout << "\nВысота колеса: " << koleso->visota;
		cout << "\nТип диска: " << koleso->tip_diska;
	}
	else
	{
		cout << "Информация о колесе еще не была добавлена";
	}
}

//функция просмотра общей информации
void prosmotr_obchee( obchee *obchie)
{
	if (obchie->obem_benzobaka >= 0)
	{
		cout << "\n\nОБЩАЯ ИНФОРМАЦИЯ:\nМодель: " << obchie->name;
		cout << "\nТип привода: " << obchie->tip_privoda;
		cout << "\nТип топлива: " << obchie->tip_topliva;
		cout << "\nКоличество посадочных мест: " << obchie->kolvo_mest;
		cout << "\nВремя разгона до 100км/ч: " << obchie->razgon_do_100;
		cout << "\nОбъем бензобака: " << obchie->obem_benzobaka;
		cout << "\nМасса: " << obchie->massa;
	}
	else
	{
		cout << "Обшая информация отсутствует";
	}
}

//функция просмотра информации о коробке переключения
void prosmotr_korobka( korobka_peredach* korobka_peredach1)
{
	if (korobka_peredach1->kolvo_peredach >= 0)
	{
		cout << "\n\nИНФОРМАЦИЯ О КОРОБКЕ ПЕРЕКЛЮЧЕНИЯ ПЕРЕДАЧ\nТип коробки переключения передач: " << korobka_peredach1->tip_korobki;
		cout << "\nКоличество передач коробки: " << korobka_peredach1->kolvo_peredach;
	}
	else
	{
		cout << "Информации о коробках передач отсутствует";
	}
}

//функция просмотра информации о водителе
void prosmotr_vod(voditel* vod)
{
	cout << "\n\nИНФОРМАЦИЯ О ВОДИТЕЛЕ:\nФИО: " << vod->name;
	cout << "\nВозраст: " << vod->age;
	cout << "\nПол: " << vod->pol;
	cout << "\nСтатус Covid-19: " << vod->covid_19;
	cout << "\nСтаж: " << vod->stag << "\n***************************************\n\n";
}

void prosmotr_avto(avto* avtomobil)
{
	prosmotr_obchee(&avtomobil->har5);
	prosmotr_motor(&avtomobil->har2);
	prosmotr_kolesa(&avtomobil->har3);
	prosmotr_korobka(&avtomobil->har4);

	if (avtomobil->vod != NULL)
	{
		prosmotr_vod(avtomobil->vod);
	}
}
//функция просмотра комплектующих и автомобиля
void prosmotr_agr(struct motor* motorishe, struct kolesa* koleso, struct obchee* obchie, struct korobka_peredach* korobka_peredach1, struct avto* avtomobil, struct voditel *vod)
{
	int menu;
	system("cls");
	cout << "1) Просмотр двигателей\n2) Просмотр колес\n3) Просмотр общих характеристик\n4) Просмотр коробок передач\n5) Просмотр авто\n6) Просмотр водителя";
	menu = _getch();
	system("cls");
	if (menu == '1')
	{
		prosmotr_motor(motorishe);
	}
	else if (menu == '2')
	{
		prosmotr_kolesa(koleso);
	}
	else if (menu == '3')
	{
		prosmotr_obchee(obchie);
	}
	else if (menu == '4')
	{
		prosmotr_korobka(korobka_peredach1);
	}
	else if (menu == '5')
	{
		if (avtomobil->har2.kol_vo_cilindr >= 0)
		{
			prosmotr_avto(avtomobil);
		}
		else
		{
			cout << "Информация об автомобиле отсутствует";
		}
	}
	else if (menu== '6')
	{
		if (vod->age >= 0)
		{
			prosmotr_vod(vod);
		}
		else
		{
			cout << "Информация о водителе отсутствует";
		}
	}
	cout << "\n\nДля возврата в меню нажмите любую клавишу";
	_getch();
}

//функция для редактирования информации о водителе
void redaktir_vod(struct voditel* vod)
{
	system("cls");
	if (vod->age > 0)
	{
		int numb_punkt = 0;
		do
		{
			system("cls");
			cout << "\n1) ФИО (" << vod->name << ")";
			cout << "\n2) Возраст (" << vod->age << ")";
			cout << "\n3) Пол (" << vod->pol << ")";
			cout << "\n4) Статус Covid-19  (" << vod->covid_19 << ")";
			cout << "\n5) Стаж (" << vod->stag << ")";
			cout << "\n\nВыберите пункт для редактирования информации: ";
			scanf("%d", &numb_punkt);
			while (getchar() != '\n');
		} while (numb_punkt < 1 || numb_punkt > 5);
		new_vod(vod, numb_punkt);
	}
	else
	{
		cout << "Информация о водителях отсутствует.\n\nДля выхода в меню нажмите любую клавишу";
		_getch();
	}
	
	
}

//Функции привязки/отвязки водителя + автомобиль
void privyazka(avto* avtomobil, voditel* vod)
{
	int menu_p;
	system("cls");
	if (vod->age >= 0 && avtomobil->har2.kol_vo_cilindr >= 0)
	{
		cout << "1) Привязка водителя\n2) Отвязка водителя";
		menu_p = _getch();
		if (menu_p == '1')
		{
			avtomobil->vod = vod;
			cout << "\n\nПривязка водителя выполнена успешна.";
		}
		else if (menu_p == '2')
		{
			avtomobil->vod = NULL;
			cout << "\n\nОтвязка водителя выполнена успешна.";
		}
	}
	else
	{
		if (vod->age < 0)
		{
			cout << "Водитель для привязки не найден.";
		}
		else if (avtomobil->har2.kol_vo_cilindr < 0)
		{
			cout << "Автомобиль для привязки не найден.";
		}
	}
	cout << "\n\nДля возврата в меню нажмите любую клавишу";
	_getch();
}


void demo(avto *mashina1, voditel *vod1)
{
	int kol_vo_m;
	do
	{
		system("cls");
		cout << "Введите количество новых автомобилей (не более 9): ";
		kol_vo_m = _getch();
	} while (kol_vo_m > 0 && kol_vo_m < 9);
	mashina1 = (avto*)malloc(kol_vo_m * sizeof(avto));
	new_car(&mashina1[0]);
}
//главное меню
void gl_menu()
{
	struct motor motorishe;
	struct kolesa koleso;
	struct obchee obchie;
	struct korobka_peredach korobka_peredach1;
	struct avto avtomobil;
	struct voditel vod;
	int menu;
	do
	{

		system("cls");
		cout << "\n1) Новый двигатель\n2) Новые колеса\n3) Новые общие характеристики\n4) Новая коробка передач\n5) Новый авто\n6) Просмотр агрегатов, авто и водителей\n7) Новый водитель\n8) Изменить информацию о водителе\n9) Демо версия (сравнение авто, добавление списка авто)\n0) Привязка водителя к автомобилю\n\nESC - выход";
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
			prosmotr_agr(&motorishe, &koleso, &obchie, &korobka_peredach1, &avtomobil, &vod);
		}
		else if (menu == '7')
		{
			new_vod(&vod, 0);
		}
		else if (menu == '8')
		{
			redaktir_vod(&vod);
		}
		else if (menu == '9')
		{
			demo();
		}
		else if (menu == '0')
		{
			privyazka(&avtomobil, &vod);
		}
		
	} while (menu != 27);

}
