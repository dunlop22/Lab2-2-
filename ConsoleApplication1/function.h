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
void new_motor(struct motor *motorishe)
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

void prosmotr_agr()
{
	int menu;
	cout << "1) �������� ����������\n2) �������� �����\n3) �������� ����� �������������\n4) �������� ������� �������\n5) �������� ����\n0) ������� � ����";
	menu = _getch();
	if (menu == '1');
}

void gl_menu()
{
	struct motor motorishe;
	struct kolesa koleso;
	int menu;
	cout << "\n1) ����� ���������\n2) ����� ������\n3) ����� ����� ��������������\n4) ����� ������� �������\n5) ����� ����\n6) ������� ��������� � ����";
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
