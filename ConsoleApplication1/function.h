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

//������� �������� ������ ���������
void new_motor( motor* motorishe)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) ���� ����������� ������ � ���������\n2) �������� �� ������������";
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
		while (scanf("%lf", &motorishe->rab_obem) != 1 || motorishe->rab_obem < 0)
		{
			printf("������� ������� �������� ������ ���������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ���������� ���������� ���: ";
		while (scanf("%lf", &motorishe->koni) != 1 || motorishe->koni < 0)
		{
			printf("������� ������� �������� ���������� ��������� ���, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ������� ������ ������� �� 100�� � ������: ";
		while (scanf("%lf", &motorishe->rasxod) != 1 || motorishe->rasxod < 0)
		{
			printf("������� ������� �������� ������� �� 100��, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ���������� ���������: ";
		while (scanf("%lf", &motorishe->kol_vo_cilindr) != 1 || motorishe->kol_vo_cilindr < 0)
		{
			printf("������� ������� �������� ���������� ���������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ���������� �������� �� ���� �������: ";
		while (scanf("%lf", &motorishe->klapan) != 1 || motorishe->klapan < 0)
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
void new_kolesa( kolesa* koleso)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) ���� ����������� ������ � �������\n2) �������� �� ������������";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
	{
		system("cls");
		cout << "���������� ���������� � ������� ����������\n\n������� ������ ������: ";
		while (scanf("%lf", &koleso->shirina) != 1 || koleso->shirina < 0)
		{
			printf("������� ������� �������� ������ ������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ������ ������: ";
		while (scanf("%lf", &koleso->visota) != 1 || koleso->visota < 0)
		{
			printf("������� ������� �������� ������ ������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ������� ������ � ������: ";
		while (scanf("%lf", &koleso->diametr) != 1 || koleso->diametr < 0)
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

//������� �������� ����� �������������
void new_obchee( obchee* obchie)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) ���� ����������� ������ �� �����\n2) �������� �� ������������";
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
		while (scanf("%lf", &obchie->kolvo_mest) != 1 || obchie->kolvo_mest < 0)
		{
			printf("������� �������� �������� ���������� ���������� ����, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ������� �� 100��/�: ";
		while (scanf("%lf", &obchie->razgon_do_100) != 1 || obchie->razgon_do_100 < 0)
		{
			printf("������� �������� �������� ������� �� 100��/�, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ����������: ";
		while (scanf("%lf", &obchie->massa) != 1 || obchie->massa < 0)
		{
			printf("������� �������� �������� �����, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ��������� � ������: ";
		while (scanf("%lf", &obchie->obem_benzobaka) != 1 || obchie->obem_benzobaka < 0 )
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

//������� �������� ����� ������� �������
void new_korobka( korobka_peredach* korobka_peredach1)
{
	int menu;
	do
	{
		system("cls");
		cout << "\n1) ���� ����������� ������ � ������� �������\n2) �������� �� ������������";
		menu = _getch();
	} while (menu != '1' && menu != '2');
	system("cls");
	if (menu == '1')
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
		while (scanf("%lf", &korobka_peredach1->kolvo_peredach) != 1 || korobka_peredach1->kolvo_peredach < 0)
		{
			printf("������� ������� �������� ���������� �������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
	else
	{
		strcpy(korobka_peredach1->tip_korobki, "����");
		korobka_peredach1->kolvo_peredach = 5;
	}
}

//������� �������� ������ ��������
void new_vod(voditel* vod, int red)
{
	int menu = '1';
	if (red == 0)
	{
		do
		{
			system("cls");
			cout << "1) ���� ����������� ������ � ��������\n2) �������� �� ������������";
			menu = _getch();
		} while (menu != '1' && menu != '2');
	}
	system("cls");
	if (menu == '1')
	{
		if (red == 1 || red == 0)
		{
			cout << "������� ��� �������� : ";
			gets_s(vod->name);
			while (strlen(vod->name) == 0)
			{
				printf("������� ������ ��� ��������, ���������� ���: ");
				gets_s(vod->name);
			}
		}
		if (red == 2 || red == 0)
		{
			cout << "������� �������: ";
			while (scanf("%lf", &vod->age) != 1)
			{
				printf("������� ������ ������� ��������, ���������� ���: ");
				while (getchar() != '\n');
			}
			while (getchar() != '\n');
		}
		if (red == 3 || red == 0)
		{
			cout << "������� ��� �������� (�/�): ";
			gets_s(vod->pol);
			while (strlen(vod->pol) == 0)
			{
				printf("������� ������ ��� ��������, ���������� ���: ");
				gets_s(vod->pol);
			}
		}
		
		if (red == 4 || red == 0)
		{
			cout << "������� ������ Covid-19 (���������/������/����������): ";
			gets_s(vod->covid_19);
			while (strlen(vod->covid_19) == 0)
			{
				printf("������� ������ ������ COVID-19, ���������� ���: ");
				gets_s(vod->covid_19);
			}
		}
		
		if (red == 5 || red == 0)
		{
			cout << "������� ���� ��������: ";
			while (scanf("%lf", &vod->stag) != 1)
			{
				printf("������� ������ ���� ��������, ���������� ���: ");
				while (getchar() != '\n');
			}
			while (getchar() != '\n');
		}
	}
	else
	{
		strcpy(vod->name, "������ �.�.");
		strcpy(vod->covid_19, "����������");
		strcpy(vod->pol, "�");
		vod->age = 23;
		vod->stag = 1;
	}
}

//������� �������� ������ ����������
void new_car( avto* avtomobil)
{
	new_motor(&avtomobil->har2);
	new_obchee(&avtomobil->har5);
	new_korobka(&avtomobil->har4);
	new_kolesa(&avtomobil->har3);
}

//������� ��������� ���������� � ���������
void prosmotr_motor(motor* motorishe)
{
	if (motorishe->rasxod >= 0)
	{
		cout << "\n\n��������� � ���������:\n���������� ���������: " << motorishe->name;
		cout << "\n������� �����: " << motorishe->rab_obem;
		cout << "\n�������� (�.�.): " << motorishe->koni;
		cout << "\n������� ������ �� 100��: " << motorishe->rasxod;
		cout << "\n���������� ���������: " << motorishe->kol_vo_cilindr;
		cout << "\n���������� �������� �� 1 �������: " << motorishe->klapan;
	}
	else
	{
		cout << "���������� � ��������� �����������";
	}
}

//������� ��������� ���������� � �������
void prosmotr_kolesa(kolesa *koleso)
{
	if (koleso->visota >= 0)
	{
		cout << "\n\n���������� � �������\n������ ������: " << koleso->shirina;
		cout << "\n������� ������: " << koleso->diametr;
		cout << "\n������ ������: " << koleso->visota;
		cout << "\n��� �����: " << koleso->tip_diska;
	}
	else
	{
		cout << "���������� � ������ ��� �� ���� ���������";
	}
}

//������� ��������� ����� ����������
void prosmotr_obchee( obchee *obchie)
{
	if (obchie->obem_benzobaka >= 0)
	{
		cout << "\n\n����� ����������:\n������: " << obchie->name;
		cout << "\n��� �������: " << obchie->tip_privoda;
		cout << "\n��� �������: " << obchie->tip_topliva;
		cout << "\n���������� ���������� ����: " << obchie->kolvo_mest;
		cout << "\n����� ������� �� 100��/�: " << obchie->razgon_do_100;
		cout << "\n����� ���������: " << obchie->obem_benzobaka;
		cout << "\n�����: " << obchie->massa;
	}
	else
	{
		cout << "����� ���������� �����������";
	}
}

//������� ��������� ���������� � ������� ������������
void prosmotr_korobka( korobka_peredach* korobka_peredach1)
{
	if (korobka_peredach1->kolvo_peredach >= 0)
	{
		cout << "\n\n���������� � ������� ������������ �������\n��� ������� ������������ �������: " << korobka_peredach1->tip_korobki;
		cout << "\n���������� ������� �������: " << korobka_peredach1->kolvo_peredach;
	}
	else
	{
		cout << "���������� � �������� ������� �����������";
	}
}

//������� ��������� ���������� � ��������
void prosmotr_vod(voditel* vod)
{
	cout << "\n\n���������� � ��������:\n���: " << vod->name;
	cout << "\n�������: " << vod->age;
	cout << "\n���: " << vod->pol;
	cout << "\n������ Covid-19: " << vod->covid_19;
	cout << "\n����: " << vod->stag << "\n***************************************\n\n";
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
//������� ��������� ������������� � ����������
void prosmotr_agr(struct motor* motorishe, struct kolesa* koleso, struct obchee* obchie, struct korobka_peredach* korobka_peredach1, struct avto* avtomobil, struct voditel *vod)
{
	int menu;
	system("cls");
	cout << "1) �������� ����������\n2) �������� �����\n3) �������� ����� �������������\n4) �������� ������� �������\n5) �������� ����\n6) �������� ��������";
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
			cout << "���������� �� ���������� �����������";
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
			cout << "���������� � �������� �����������";
		}
	}
	cout << "\n\n��� �������� � ���� ������� ����� �������";
	_getch();
}

//������� ��� �������������� ���������� � ��������
void redaktir_vod(struct voditel* vod)
{
	system("cls");
	if (vod->age > 0)
	{
		int numb_punkt = 0;
		do
		{
			system("cls");
			cout << "\n1) ��� (" << vod->name << ")";
			cout << "\n2) ������� (" << vod->age << ")";
			cout << "\n3) ��� (" << vod->pol << ")";
			cout << "\n4) ������ Covid-19  (" << vod->covid_19 << ")";
			cout << "\n5) ���� (" << vod->stag << ")";
			cout << "\n\n�������� ����� ��� �������������� ����������: ";
			scanf("%d", &numb_punkt);
			while (getchar() != '\n');
		} while (numb_punkt < 1 || numb_punkt > 5);
		new_vod(vod, numb_punkt);
	}
	else
	{
		cout << "���������� � ��������� �����������.\n\n��� ������ � ���� ������� ����� �������";
		_getch();
	}
	
	
}

//������� ��������/������� �������� + ����������
void privyazka(avto* avtomobil, voditel* vod)
{
	int menu_p;
	system("cls");
	if (vod->age >= 0 && avtomobil->har2.kol_vo_cilindr >= 0)
	{
		cout << "1) �������� ��������\n2) ������� ��������";
		menu_p = _getch();
		if (menu_p == '1')
		{
			avtomobil->vod = vod;
			cout << "\n\n�������� �������� ��������� �������.";
		}
		else if (menu_p == '2')
		{
			avtomobil->vod = NULL;
			cout << "\n\n������� �������� ��������� �������.";
		}
	}
	else
	{
		if (vod->age < 0)
		{
			cout << "�������� ��� �������� �� ������.";
		}
		else if (avtomobil->har2.kol_vo_cilindr < 0)
		{
			cout << "���������� ��� �������� �� ������.";
		}
	}
	cout << "\n\n��� �������� � ���� ������� ����� �������";
	_getch();
}


void demo(avto *mashina1, voditel *vod1)
{
	int kol_vo_m;
	do
	{
		system("cls");
		cout << "������� ���������� ����� ����������� (�� ����� 9): ";
		kol_vo_m = _getch();
	} while (kol_vo_m > 0 && kol_vo_m < 9);
	mashina1 = (avto*)malloc(kol_vo_m * sizeof(avto));
	new_car(&mashina1[0]);
}
//������� ����
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
		cout << "\n1) ����� ���������\n2) ����� ������\n3) ����� ����� ��������������\n4) ����� ������� �������\n5) ����� ����\n6) �������� ���������, ���� � ���������\n7) ����� ��������\n8) �������� ���������� � ��������\n9) ���� ������ (��������� ����, ���������� ������ ����)\n0) �������� �������� � ����������\n\nESC - �����";
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
