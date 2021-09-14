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
void new_kolesa(struct kolesa* koleso)
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
void new_obchee(struct obchee* obchie)
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
void new_korobka(struct korobka_peredach* korobka_peredach1)
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
void new_vod(struct voditel* vod)
{
	int menu;
	do
	{
		system("cls");
		cout << "1) Ввод собственных данных о водителе\n2)Создание по конструктору";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{

		cout << "Введите ФИО водителя : ";
		gets_s(vod->name);
		while (strlen(vod->name) == 0)
		{
			printf("Неверно введен ФИО водителя, попробуйте еще: ");
			gets_s(vod->name);
		}

		cout << "Введите возраст: ";
		while (scanf("%lf", &vod->age) != 1)
		{
			printf("Неверно введен возраст водителя, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
		cout << "Введите пол водителя (М/Ж): ";
		gets_s(vod->pol);
		while (strlen(vod->pol) == 0)
		{
			printf("Неверно введен пол водителя, попробуйте еще: ");
			gets_s(vod->pol);
		}

		cout << "Введите статус Covid-19 (переболел/привит/неизвестно): ";
		gets_s(vod->covid_19);
		while (strlen(vod->covid_19) == 0)
		{
			printf("Неверно введен статус COVID-19, попробуйте еще: ");
			gets_s(vod->covid_19);
		}
		cout << "Введите стаж водителя: ";
		while (scanf("%lf", &vod->stag) != 1)
		{
			printf("Неверно введен стаж водителя, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
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
void new_car(struct avto* avtomobil)
{
	new_motor(&avtomobil->har2);
	new_obchee(&avtomobil->har5);
	new_korobka(&avtomobil->har4);
	new_kolesa(&avtomobil->har3);
}

//функция просмотра информации о двигателе
void prosmotr_motor(struct motor* motorishe)
{
	cout << "\n\nИНФОРАЦИЯ О ДВИГАТЕЛЕ:\nМаркировка двигателя: " << motorishe->name;
	cout << "\nРабочий объем: " << motorishe->rab_obem;
	cout << "\nМощность (л.с.): " << motorishe->koni;
	cout << "\nСредний расход на 100км: " << motorishe->rasxod;
	cout << "\nКоличество цилиндров: " << motorishe->kol_vo_cilindr;
	cout << "\nКоличество клапанов на 1 цилиндр: " << motorishe->klapan;
}

//функция просмотра информации о колесах
void prosmotr_kolesa(struct kolesa *koleso)
{
	if (koleso->tip_diska != NULL)
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
void prosmotr_obchee(struct obchee *obchie)
{
	cout << "\n\nОБЩАЯ ИНФОРМАЦИЯ:\nМодель: " << obchie->name;
	cout << "\nТип привода: " << obchie->tip_privoda;
	cout << "\nТип топлива: " << obchie->tip_topliva;
	cout << "\nКоличество посадочных мест: " << obchie->kolvo_mest;
	cout << "\nВремя разгона до 100км/ч: " << obchie->razgon_do_100;
	cout << "\nОбъем бензобака: " << obchie->obem_benzobaka;
	cout << "\nМасса: " << obchie->massa;
}

//функция просмотра информации о коробке переключения
void prosmotr_korobka(struct korobka_peredach* korobka_peredach1)
{
	cout << "\n\nИНФОРМАЦИЯ О КОРОБКЕ ПЕРЕКЛЮЧЕНИЯ ПЕРЕДАЧ\nТип коробки переключения передач: " << korobka_peredach1->tip_korobki;
	cout << "\nКоличество передач коробки: " << korobka_peredach1->kolvo_peredach;
}

//функция просмотра информации о водителе
void prosmotr_vod(struct voditel* vod)
{
	int i;
	cout << "\nФИО: " << vod->name;
	cout << "\nВозраст: " << vod->age;
	cout << "\nПол: " << vod->pol;
	cout << "\nСтатус Covid-19: " << vod->covid_19;
	cout << "\nСтаж: " << vod->stag << "\n***************************************\n\n";
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
		prosmotr_motor(&avtomobil->har2);
		prosmotr_kolesa(&avtomobil->har3);
		prosmotr_obchee(&avtomobil->har5);
		prosmotr_korobka(&avtomobil->har4);
	}
	else if (menu== '6')
	{
		prosmotr_vod(vod);
	}
	
	cout << "\n\nДля возврата в меню нажмите любую клавишу";
	_getch();
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
		cout << "\n1) Новый двигатель\n2) Новые колеса\n3) Новые общие характеристики\n4) Новая коробка передач\n5) Новый авто\n6) Просмотр агрегатов, авто и водителей\n7) Новый водитель\n8) Изменить информацию о водителе\n\nESC - выход";
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
			new_vod(&vod);
		}
		else if (menu == '8')
		{

		}
	} while (menu != 27);

}
