#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;

//������� �������� ������ ���������
void new_motor(struct motor* motorishe)
{
	int menu;
	do
	{
		system("cls");
		cout << "1) ���� ����������� ������ � ���������\n2)�������� �� ������������";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{
		cout << "������� ���������� ���������: ";
		gets_s(motorishe->name);
		while (strlen(motorishe->name) == 0)
		{
			printf("������� ������� ���������� ���������, ���������� ���: ");
			gets_s(motorishe->name);
		}
		cout << "������� ������� ����� ��������� � ������: ";
		while (scanf("%lf", &motorishe->rab_obem) != 1)
		{
			printf("������� ������� �������� ������ ���������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ���������� ���������� ���: ";
		while (scanf("%lf", &motorishe->koni) != 1)
		{
			printf("������� ������� �������� ���������� ��������� ���, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ������� ������ ������� �� 100�� � ������: ";
		while (scanf("%lf", &motorishe->rasxod) != 1)
		{
			printf("������� ������� �������� ������� �� 100��, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ���������� ���������: ";
		while (scanf("%lf", &motorishe->kol_vo_cilindr) != 1)
		{
			printf("������� ������� �������� ���������� ���������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ���������� �������� �� ���� �������: ";
		while (scanf("%lf", &motorishe->klapan) != 1)
		{
			printf("������� ������� �������� ���������� ��������, ���������� ���: ");
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

//������� �������� ����� �����
void new_kolesa(struct kolesa* koleso)
{
	int menu;
	do
	{
		system("cls");
		cout << "1) ���� ����������� ������ � �������\n2)�������� �� ������������";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{
		system("cls");
		cout << "���������� ���������� � ������� ����������\n\n������� ������ ������: ";
		while (scanf("%lf", &koleso->shirina) != 1)
		{
			printf("������� ������� �������� ������ ������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ������ ������: ";
		while (scanf("%lf", &koleso->visota) != 1)
		{
			printf("������� ������� �������� ������ ������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ������� ������ � ������: ";
		while (scanf("%lf", &koleso->diametr) != 1)
		{
			printf("������� ������� �������� �������� ������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ��� ��������� ����� (���������/�����/�����): ";
		gets_s(koleso->tip_diska);
		while (strlen(koleso->tip_diska) == 0)
		{
			printf("������� ������ ��� ��������� �����, ���������� ���: ");
			gets_s(koleso->tip_diska);
		}
	}
	else
	{
		strcpy(koleso->tip_diska, "���������");
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
		cout << "1) ���� ����������� ������ � �������\n2)�������� �� ������������";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{
		cout << "���������� ����� ���������� �� ����������\n\n������� ������ ����������: ";
		gets_s(obchie->name);
		while (strlen(obchie->name) == 0)
		{
			printf("������� ������� ������ ����������, ���������� ���: ");
			gets_s(obchie->name);
		}

		cout << "������� ��� ������� (2WD/4WD): ";
		gets_s(obchie->tip_privoda);
		while (strlen(obchie->tip_privoda) == 0)
		{
			printf("������� ������ ��� �������, ���������� ���: ");
			gets_s(obchie->tip_privoda);
		}

		cout << "������� ��� ������� (������/������/�������): ";
		gets_s(obchie->tip_topliva);
		while (strlen(obchie->tip_topliva) == 0)
		{
			printf("������� ������ ��� �������, ���������� ���: ");
			gets_s(obchie->tip_topliva);
		}

		cout << "������� ���������� ���������� ����: ";
		while (scanf("%lf", &obchie->kolvo_mest) != 1)
		{
			printf("������� �������� �������� ���������� ���������� ����, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ������� �� 100��/�: ";
		while (scanf("%lf", &obchie->razgon_do_100) != 1)
		{
			printf("������� �������� �������� ������� �� 100��/�, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ����������: ";
		while (scanf("%lf", &obchie->massa) != 1)
		{
			printf("������� �������� �������� �����, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ��������� � ������: ";
		while (scanf("%lf", &obchie->obem_benzobaka) != 1)
		{
			printf("������� �������� �������� ������ ���������, ���������� ���: ");
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
		strcpy(obchie->tip_topliva, "������");
	}
}

void new_korobka(struct korobka_peredach* korobka_peredach1)
{
	system("cls");
	cout << "���������� ���������� � ������� ������� ����������\n\n������� ��� ������� ������� (����/����): ";
	gets_s(korobka_peredach1->tip_korobki);
	while (strlen(korobka_peredach1->tip_korobki) == 0)
	{
		printf("������� ������� ������ ����������, ���������� ���: ");
		gets_s(korobka_peredach1->tip_korobki);
	}

	cout << "������� ���������� ������� �������: ";
	while (scanf("%lf", &korobka_peredach1->kolvo_peredach) != 1)
	{
		printf("������� ������� �������� ���������� �������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

}
//������� �������� ������ ����������
void new_car(struct avto* avtomobil)
{
	new_motor(&avtomobil->har2);
	new_obchee(&avtomobil->har5);
	new_korobka(&avtomobil->har4);
	new_kolesa(&avtomobil->har3);
}

//������� ��������� ������������� � ����������
void prosmotr_agr(struct motor* motorishe, struct kolesa* koleso, struct obchee* obchie, struct korobka_peredach* korobka_peredach1, struct avto* avtomobil)
{
	int menu;
	system("cls");
	cout << "1) �������� ����������\n2) �������� �����\n3) �������� ����� �������������\n4) �������� ������� �������\n5) �������� ����\n0) ������� � ����";
	menu = _getch();
	if (menu == '1')
	{
		cout << "\n\n��������� � ���������:\n���������� ���������: " << motorishe->name;
		cout << "\n������� �����: " << motorishe->rab_obem;
		cout << "\n�������� (�.�.): " << motorishe->koni;
		cout << "\n������� ������ �� 100��: " << motorishe->rasxod;
		cout << "\n���������� ���������: " << motorishe->kol_vo_cilindr;
		cout << "\n���������� �������� �� 1 �������: " << motorishe->klapan;
	}
	else if (menu == '2')
	{
		cout << "\n\n���������� � �������\n������ ������: " << koleso->shirina;
		cout << "\n������� ������: " << koleso->diametr;
		cout << "\n������ ������: " << koleso->visota;
		cout << "\n��� �����: " << koleso->tip_diska;
	}
	else if (menu == '3')
	{
		cout << "\n\n����� ����������:\n������: " << obchie->name;
		cout << "\n��� �������: " << obchie->tip_privoda;
		cout << "\n��� �������: " << obchie->tip_topliva;
		cout << "\n���������� ���������� ����: " << obchie->kolvo_mest;
		cout << "\n����� ������� �� 100��/�: " << obchie->razgon_do_100;
		cout << "\n����� ���������: " << obchie->obem_benzobaka;
		cout << "\n�����: " << obchie->massa;
	}
	else if (menu == '4')
	{
		cout << "\n\n���������� � ������� ������������ �������\n��� ������� ������������ �������: " << korobka_peredach1->tip_korobki;
		cout << "\n���������� ������� �������: " << korobka_peredach1->kolvo_peredach;
	}
	cout << "��� �������� � ���� ������� ����� �������";
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
		cout << "\n1) ����� ���������\n2) ����� ������\n3) ����� ����� ��������������\n4) ����� ������� �������\n5) ����� ����\n6) ������� ��������� � ����\n\nESC - �����";
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
