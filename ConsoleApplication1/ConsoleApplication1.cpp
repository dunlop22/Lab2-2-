#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <io.h>
#include "function.h"

int main()
{
    int black = 0;
    int white = 15;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((white << 4) | black));

    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    gl_menu();
}
