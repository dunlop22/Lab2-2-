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
void new_motor()
{

}

void gl_menu()
{
	int menu;
	cout << "1) ����� ���������\n2)����� ������";
	menu = _getch();
	if (menu == '1')
	{
		new_motor();
	}
	else if (menu == '2')
	{

	}

}
