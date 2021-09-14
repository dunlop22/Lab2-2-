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
void new_motor()
{

}

void gl_menu()
{
	int menu;
	cout << "1) Новый двигатель\n2)Новые колеса";
	menu = _getch();
	if (menu == '1')
	{
		new_motor();
	}
	else if (menu == '2')
	{

	}

}
