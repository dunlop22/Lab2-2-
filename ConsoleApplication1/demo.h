#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include "function.h"
#include "struct.h"
#include <fcntl.h>
using namespace std;

//function.h
void prosmotr_avto(avto *avtomobil);
void prosmotr_kolesa(kolesa* koleso);
void prosmotr_obchee(obchee* obchie);
void prosmotr_korobka(korobka_peredach* korobka_peredach1);
void prosmotr_motor(motor* motorishe);
void new_car(avto* avtomobil);
void new_vod(voditel* vod, int red);
void prosmotr_vod(voditel* vod);


void setON()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
}
void setOFF()
{
    _setmode(_fileno(stdout), O_TEXT);
    _setmode(_fileno(stdin), O_TEXT);
}
void tip(string name)
{
    int i;
    setON();
    wcout << L"\u2551";
    setOFF();
    cout << name;
    for (i = 0; i + name.length() < 23; i++)
    {
        cout << " ";
    }
}

//функция для вывода верхней полосы шапки таблицы сравнения авто
void up_polosa()
{
    int i;
    setON();
    wcout << L"\u2554";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u2566";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u2566";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u2557";
    setOFF();
}

//функция для вывода нижней полосы шапки таблицы сравнения авто
void down_polosa()
{
    int i;
    setON();
    wcout << L"\u255A";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u2569";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u2569";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u255D";
    setOFF();
}

//функция для вывода разделительной полосы в таблице сравнения авто
void polosa()
{
    int i;
    setON();
    wcout << L"\u2560";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u256C";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u256C";
    for (i = 0; i < 23; i++)
    {
        wcout << L"\u2550";
    }
    wcout << L"\u2563";
    setOFF();
    cout << "\n";
}

//функция удаления информации о водителе
void del_vod(struct voditel* vod, int* kol_vo_vodit, struct avto* mashina, int vsego)
{
    int numb, i;
    do
    {
        system("cls");
        for (i = 0; i < *kol_vo_vodit; i++)
        {
            prosmotr_vod(vod);
        }
        
        cout << "\n\nВведите номер водителя для удаления: ";
        scanf("%d", &numb);
        while (getchar() != '\n');
    } while (numb < 1 || numb > *kol_vo_vodit);

    struct voditel* vod_dubl;
    vod_dubl = (voditel*)malloc(1 * sizeof(voditel));
    for (i = numb - 1; i < *kol_vo_vodit - 1; i++)
    {
        *vod_dubl = vod[i];
        vod[i] = vod[i + 1];
    }
    *kol_vo_vodit = *kol_vo_vodit - 1;

}

//функция удаления информации об авто
void del_avto(struct avto* mashina, int* vsego, struct voditel* vod)
{
    int numb, i;
    do
    {
        system("cls");
        for (i = 0; i < *vsego; i++)
        {
            cout << "\n\n\nАВТОМОБИЛЬ №" << i + 1;
            prosmotr_avto(&mashina[i]);
        }
        cout << "\n\nВведите номер авто для удаления: ";
        scanf("%d", &numb);
        while (getchar() != '\n');
    } while (numb < 1 || numb > *vsego);

    //перенос всех машин вниз
    for (i = numb - 1; i < *vsego - 1; i++)
    {
        struct avto* avto_dubl;
        avto_dubl = (avto*)malloc(1 * sizeof(avto));
        *avto_dubl = mashina[i];
        mashina[i] = mashina[i + 1];
    }
    *vsego = *vsego - 1;
}

//функция анализа данных авто
void compare(double inf1, double inf2)
{
    int green = 10;
    int black = 0;
    int white = 15;

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    int temp, n, i;
    n = 0;
    setON();
    wcout << L"\u2551";
    setOFF();
    temp = inf1;
    n = 0;
    while ((temp /= 10) > 0) n++;
    if (inf1 > inf2)
    {
        SetConsoleTextAttribute(hConsole, (WORD)((white << 4) | green));
        printf("%.2f", inf1);
        SetConsoleTextAttribute(hConsole, (WORD)((white << 4) | black));
        for (i = 0; i + n < 19; i++)
        {
            cout << " ";
        }
        setON();
        wcout << L"\u2551";
        setOFF();
        temp = inf2;
        n = 0;
        while ((temp /= 10) > 0) n++;
        printf("%.2f", inf2);
        for (i = 0; i + n < 19; i++)
        {
            cout << " ";
        }
    }
    else if (inf1 < inf2)
    {
        printf("%.2f", inf1);
        for (i = 0; i + n < 19; i++)
        {
            cout << " ";
        }
        setON();
        wcout << L"\u2551";
        setOFF();
        temp = inf2;
        n = 0;
        while ((temp /= 10) > 0) n++;
        SetConsoleTextAttribute(hConsole, (WORD)((white << 4) | green));
        printf("%.2f", inf2);
        SetConsoleTextAttribute(hConsole, (WORD)((white << 4) | black));
        for (i = 0; i + n < 19; i++)
        {
            cout << " ";
        }
    }
    else
    {
        printf("%.2f", inf1);
        for (i = 0; i + n < 19; i++)
        {
            cout << " ";
        }
        setON();
        wcout << L"\u2551";
        setOFF();
        temp = inf2;
        n = 0;
        while ((temp /= 10) > 0) n++;
        printf("%.2f", inf2);
        for (i = 0; i + n < 19; i++)
        {
            cout << " ";
        }
    }
    setON();
    wcout << L"\u2551";
    setOFF();
    cout << "\n";
}

//функция сравнения двух автомобилей
void compare_avto(int vsego, struct avto* mashina, struct voditel* vod)
{
    int numb1, numb2, i;
    do
    {
        system("cls");
        for (i = 0; i < vsego; i++)
        {
            cout << i + 1 << ") " << mashina[i].har5.name << "\n";
        }
        cout << "\n\nВведите номер первого авто для сравнения: ";
        scanf("%d", &numb1);
        while (getchar() != '\n');
    } while (numb1 < 1 || numb1 > vsego);
    do
    {
        system("cls");
        for (i = 0; i < vsego; i++)
        {
            cout << i + 1 << ") " << mashina[i].har5.name << "\n";
        }
        cout << "\n\nВведите номер второго авто для сравнения: ";
        scanf("%d", &numb2);
        while (getchar() != '\n');
        if (numb1 == numb2)
        {
            numb2 = 0;
        }
    } while (numb2 < 1 || numb2 > vsego);

    //сравнение основных пунктов
    system("cls");
    int green = 10;
    int black = 0;
    int white = 15;
    int temp, n;
    n = 0;

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    SetConsoleTextAttribute(hConsole, (WORD)((white << 4) | green));
    SetConsoleTextAttribute(hConsole, (WORD)((white << 4) | black));
    cout << "Зеленым выделены большие значения\n\n";
    up_polosa();
    cout << "\n";
    setON();
    wcout << L"\u2551";
    setOFF();
    for (i = 0; i < 23; i++)
    {
        cout << " ";
    }
    setON();
    wcout << L"\u2551";
    setOFF();

    cout << mashina[numb1 - 1].har5.name;
    for (i = 0; i + strlen(mashina[numb1 - 1].har5.name) < 23; i++)
    {
        cout << " ";
    }
    setON();
    wcout << L"\u2551";
    setOFF();
    cout << mashina[numb2 - 1].har5.name;
    for (i = 0; i + strlen(mashina[numb2 - 1].har5.name) < 23; i++)
    {
        cout << " ";
    }
    setON();
    wcout << L"\u2551";
    setOFF();
    cout << "\n";

    polosa();
    tip("Кол-во клапанов");
    compare(mashina[numb1 - 1].har2.klapan, mashina[numb2 - 1].har2.klapan);
    polosa();
    tip("Кол-во цилиндров");
    compare(mashina[numb1 - 1].har2.kol_vo_cilindr, mashina[numb2 - 1].har2.kol_vo_cilindr);
    polosa();
    tip("Кол - во л.с.");
    compare(mashina[numb1 - 1].har2.koni, mashina[numb2 - 1].har2.koni);
    polosa();
    tip("Рабочий объем");
    compare(mashina[numb1 - 1].har2.rab_obem, mashina[numb2 - 1].har2.rab_obem);
    polosa();
    tip("Расход на 100");
    compare(mashina[numb1 - 1].har2.rasxod, mashina[numb2 - 1].har2.rasxod);
    polosa();

    tip("Диаметр колеса");
    compare(mashina[numb1 - 1].har3.diametr, mashina[numb2 - 1].har3.diametr);
    polosa();
    tip("Высота колеса");
    compare(mashina[numb1 - 1].har3.visota, mashina[numb2 - 1].har3.visota);
    polosa();
    tip("Ширина колеса");
    compare(mashina[numb1 - 1].har3.shirina, mashina[numb2 - 1].har3.shirina);
    polosa();
    tip("Колв-во передач");
    compare(mashina[numb1 - 1].har4.kolvo_peredach, mashina[numb2 - 1].har4.kolvo_peredach);
    polosa();
    tip("Кол-во мест");
    compare(mashina[numb1 - 1].har5.kolvo_mest, mashina[numb2 - 1].har5.kolvo_mest);
    polosa();
    tip("Масса");
    compare(mashina[numb1 - 1].har5.massa, mashina[numb2 - 1].har5.massa);
    polosa();
    tip("Объем бензобака");
    compare(mashina[numb1 - 1].har5.obem_benzobaka, mashina[numb2 - 1].har5.obem_benzobaka);
    polosa();
    tip("Разгон до 100");
    compare(mashina[numb1 - 1].har5.razgon_do_100, mashina[numb2 - 1].har5.razgon_do_100);
    down_polosa();

    cout << "\n\nНажмите любую клавишу для возврата в меню";
    _getch();



}





//функция создания связи между водителем и авто
void create_vod_avto(struct avto* mashina, int vsego, int kol_vo_vodit, struct voditel* vod)
{
    int i, numb, numb_vod, func;
    do
    {
        system("cls");
        cout << "1) Привязка водителя к автомобилю\n2) Отвязка водителя от автомобиля";
        func = _getch();
    } while (func < '1' || func > '2');
    do
    {
        system("cls");
        for (i = 0; i < vsego; i++)
        {
            cout << i + 1 << ") " << mashina[i].har5.name << "\n";
        }
        cout << "\n\nВведите номер авто: ";
        scanf("%d", &numb);
        while (getchar() != '\n');
    } while (numb < 1 || numb > vsego);

    if (func == '1')
    {
        do
        {
            system("cls");
            for (i = 0; i < kol_vo_vodit; i++)
            {
                cout << "\n\nВодитель №" << i + 1;
                prosmotr_vod(vod);
            }
            cout << "\n\nВведите номер водителя для привязки к автомобилю " << mashina[numb - 1].har5.name << ": ";
            scanf("%d", &numb_vod);
            while (getchar() != '\n');
        } while (numb_vod < 1 || numb_vod > kol_vo_vodit);
        mashina[numb - 1].vod = &vod[numb_vod - 1];
        system("cls");
        cout << "Привязка водителя прошла успешно";
    }
    else
    {
        mashina[numb - 1].vod = NULL;
        system("cls");
        cout << "Отвязка водителя прошла успешно";
    }
    cout << "\n\nНажмите любую клавишу для возврата в меню.";
    _getch();
}


void demo()
{
    int menu;
    int i;
    int kol_vo_v = 0;
    int kol_vo_m = 0;
    struct avto* mashina;    //создание массива автомобилей
    struct voditel* vod1;    //создание массива водителей
    vod1 = (voditel*)malloc(0 * sizeof(voditel));
    mashina = (avto*)malloc(0 * sizeof(avto));
    do
    {
        system("cls");
        cout << "Всего автомобилей с информацией: " << kol_vo_m;
        cout << "\nВсего водителей с информацией: " << kol_vo_v;
        cout << "\n\n1) Добавить информацию о новых автомобилях\n2) Добавить информацию о новом водителе";
        if (kol_vo_m > 0)
        {
            cout << "\n3) Просмотр информации об автомобилях";
        }
        if (kol_vo_v > 0)
        {
            cout << "\n4) Просмотр информации о водителях";
        }
        if (kol_vo_m > 1)
        {
            cout << "\n5) Сравнение автомобилей";
        }
        if (kol_vo_m > 0 && kol_vo_v > 0)
        {
            cout << "\n7) Создать привязку автомобиль/водитель";
        }
        if (kol_vo_v > 0)
        {
            cout << "\n8) Удалить информацию о водителе";
        }
        if (kol_vo_m > 0)
        {
            cout << "\n9) Удалить информацию об автомобиле";
        }
        cout << "\n\nESC - выход";
        menu = _getch();
        
        if (menu == '1')
        {
            do
            {
                system("cls");
                cout << "Введите количество новых автомобилей (не более 9): ";
                kol_vo_m = _getch();
            } while (kol_vo_m < '1' && kol_vo_m > '9');
            kol_vo_m = kol_vo_m - 48;
            mashina = (avto*)malloc(kol_vo_m * sizeof(avto));
            for (i = 0; i < kol_vo_m; i++)
            {
                new_car(&mashina[i]);
                mashina[i].vod = NULL;
                cout << "Автомобиль №" << i + 1 << " успешно создан.\n\nНажмите любую клавишу для продолжения";
                _getch();
            }
        }
        if (menu == '2')
        {
            do
            {
                system("cls");
                cout << "Введите количество новых водителей (не более 9): ";
                kol_vo_v = _getch();
            } while (kol_vo_v < '1' && kol_vo_v > '9');
            kol_vo_v = kol_vo_v - 48;
            vod1 = (voditel*)malloc(kol_vo_v * sizeof(voditel));
            for (i = 0; i < kol_vo_v; i++)
            {
                new_vod(&vod1[i], 0);
            }
        }
        if (menu == '3' && kol_vo_m > 0)
        {
            system("cls");
            for (i = 0; i < kol_vo_m; i++)
            {
                cout << "\n\nАВТОМОБИЛЬ №" << i + 1;
                prosmotr_avto(&(mashina[i]));
            }
            cout << "\n\nНажмите любую клавишу для возврата в меню";
            _getch();
        }
        
        if (menu == '4' && kol_vo_v > 0)
        {
            system("cls");
            for (i = 0; i < kol_vo_v; i++)
            {
                prosmotr_vod( vod1);
            }
            cout << "\n\nДля возврата в меню нажмите любую клавишу.";
            _getch();
        }
        if (menu == '5' && kol_vo_m > 1)
        {
            compare_avto(kol_vo_m, mashina, vod1);
        }
        if (menu == '7')
        {
            create_vod_avto(mashina, kol_vo_m, kol_vo_v, vod1);
        }
        if (menu == '8' && kol_vo_v > 0)
        {
            del_vod(vod1, &kol_vo_v, mashina, kol_vo_m);
        }
        if (menu == '9' && kol_vo_m > 0)
        {
            del_avto(mashina, &kol_vo_m, vod1);
        }
    } while (menu != 27);
}
