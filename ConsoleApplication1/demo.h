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



void setON();
void setOFF();
void tip(string name);
void up_polosa();
void down_polosa();
void polosa();
void prosmotr_voditel(int vsego_vodit, struct voditel* vod);
void prosmotr_avto(int vsego, struct avto* mashina, struct voditel* vod);
void del_avto(struct avto* mashina, int* vsego, struct voditel* vod);
void compare(double inf1, double inf2);
void del_vod(struct voditel* vod, int* kol_vo_vodit, struct avto* mashina, int vsego);
void create_vod_avto(struct avto* mashina, int vsego, int kol_vo_vodit, struct voditel* vod);
void compare_avto(int vsego, struct avto* mashina, struct voditel* vod);

//функция главного меню




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

//функция просмотра информации о водителях
void prosmotr_voditel(int vsego_vodit, struct voditel* vod)
{
    int i;
    system("cls");
    for (i = 0; i < vsego_vodit; i++)
    {
        cout << "Водитель №" << i + 1;
        cout << "\nФИО: " << vod[i].name;
        cout << "\nВозраст: " << vod[i].age;
        cout << "\nПол: " << vod[i].pol;
        cout << "\nСтатус Covid-19: " << vod[i].covid_19;
        cout << "\nСтаж: " << vod[i].stag << "\n***************************************\n\n";
    }
}

void vivod_kolesa(struct kolesa* koleso)
{
    cout << "\n\nИНФОРМАЦИЯ О КОЛЕСАХ\nШирина колеса: " << koleso->shirina;
    /*cout << "\nДиаметр колеса: " << mashina[tekuchee].har3.diametr;
    cout << "\nВысота колеса: " << mashina[tekuchee].har3.visota;
    cout << "\nТип диска: " << mashina[tekuchee].har3.tip_diska;
    */
}

//функция вывода информации о текущих автомобилях
void prosmotr_avto(int vsego, struct avto* mashina, struct voditel* vod)
{
    int i;
    for (i = 0; i < vsego; i++)
    {
        cout << "\nАвтомобиль №" << i + 1 << "\n";
        vivod_kolesa(&(mashina + i)->har3);
        /*prosmotr_korobka(&(mashina[0].har4);
        prosmotr_motor(&mashina[i].har2);
        prosmotr_obchee(&mashina[i].har5);
        /*if (mashina[i].vod != -1)
        {
            cout << "\n\nВодитель: " << vod[mashina[i].vod].name;
        }
        cout << "\n****************************\n";
        */
    }
    
}

///функция анализа данных авто
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


//функция удаления информации об авто
void del_avto(struct avto* mashina, int* vsego, struct voditel* vod)
{
    int numb, i;
    do
    {
        system("cls");
        prosmotr_avto(*vsego, mashina, vod);
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

//функция удаления информации о водителе
void del_vod(struct voditel* vod, int* kol_vo_vodit, struct avto* mashina, int vsego)
{
    int numb, i;
    do
    {
        system("cls");
        prosmotr_voditel(*kol_vo_vodit, vod);
        cout << "\n\nВведите номер водителя для удаления: ";
        scanf("%d", &numb);
        while (getchar() != '\n');
    } while (numb < 1 || numb > *kol_vo_vodit);

    for (i = numb - 1; i < *kol_vo_vodit - 1; i++)
    {
        struct voditel* vod_dubl;
        vod_dubl = (voditel*)malloc(1 * sizeof(voditel));
        *vod_dubl = vod[i];
        vod[i] = vod[i + 1];
    }
    *kol_vo_vodit = *kol_vo_vodit - 1;

    /*
    for (i = 0; i < vsego; i++)
    {
        if (mashina[i].vod == numb - 1)
        {
            mashina[i].vod = -1;
        }
    }
    */
}

//функция создания связи между водителем и авто
void create_vod_avto(struct avto* mashina, int vsego, int kol_vo_vodit, struct voditel* vod)
{
    int i, numb, numb_vod;
    do
    {
        system("cls");
        for (i = 0; i < vsego; i++)
        {
            cout << i + 1 << ") " << mashina[i].har5.name << "\n";
        }
        cout << "\n\nВведите номер авто для привязки водителя: ";
        scanf("%d", &numb);
        while (getchar() != '\n');
    } while (numb < 1 || numb > vsego);

    do
    {
        system("cls");
        prosmotr_voditel(kol_vo_vodit, vod);
        cout << "\n\nВведите номер водителя для привязки к автомобилю " << mashina[numb - 1].har5.name << ": ";
        scanf("%d", &numb_vod);
        while (getchar() != '\n');
    } while (numb_vod < 1 || numb_vod > kol_vo_vodit);
    //mashina[numb - 1].vod = numb_vod - 1;
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

int demo()
{
    int tekuchee = 0;
    int menu;
    int kol_vo_v = 0;
    int kol_vo_m = 0;
    int teck_voditel = 0;
    struct avto* mashina;    //создание массива автомобилей
    struct voditel* vod;    //создание массива водителей
    
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
        if (kol_vo_v > 0)
        {
            cout << "\n\n0) Изменение информации о водителе";
        }
        cout << "\n\nESC - выход";

        //mashina = (avto*)malloc(kol_vo_m * sizeof(avto));

        menu = _getch();
        

        mashina = (avto*)malloc(1 * sizeof(avto));
        vod = (voditel*)malloc(1 * sizeof(voditel));

        if (menu == '1')
        {
            do
            {
                system("cls");
                cout << "Введите количество новых автомобилей (не более 9): ";
                kol_vo_m = _getch();
            } while (kol_vo_m > 0 && kol_vo_m < 9);
            mashina = (avto*)malloc(kol_vo_m * sizeof(avto));
            new_car(&mashina[0]);
            //new_car(&mashina[0]);

        }
        if (menu == '2')
        {
            do
            {
                system("cls");
                cout << "Введите количество новых водителей (не более 9): ";
                kol_vo_v = _getch();
            } while (kol_vo_v > 0 && kol_vo_v < 9);
            vod = (voditel*)malloc(kol_vo_v * sizeof(voditel));
        }
        if (menu == '3' && kol_vo_m > 0)
        {
            system("cls");
            prosmotr_avto(kol_vo_m, mashina, vod);
            cout << "\n\nНажмите любую клавишу для возврата в меню";
            _getch();
        }
        if (menu == '4' && kol_vo_v > 0)
        {
            system("cls");
            prosmotr_voditel(kol_vo_v, vod);
            cout << "\n\nДля возврата в меню нажмите любую клавишу.";
            _getch();
        }
        if (menu == '5' && kol_vo_m > 1)
        {
            compare_avto(kol_vo_m, mashina, vod);
        }
        if (menu == '7')
        {
            create_vod_avto(mashina, kol_vo_m, kol_vo_v, vod);
        }
        if (menu == '8' && kol_vo_v > 0)
        {
            del_vod(vod, &kol_vo_v, mashina, kol_vo_m);
        }
        if (menu == '9' && kol_vo_m > 0)
        {
            del_avto(mashina, &kol_vo_m, vod);
        }
        if (menu == '0' && kol_vo_v > 0)
        {
            return 0;
        }
        if (menu == 27)
        {
            return 27;
        }
    } while (true);
}
