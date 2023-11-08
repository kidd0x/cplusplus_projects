#include <iostream>
#include <conio.h>
#include <windows.h>
#include <algorithm>

using namespace std;

#define MAX 10

struct
{
    int MX[3][MAX][MAX];
    int i, j, c, r;
}Mx;

int main()
{
    printf("Introdu numarul de randuri (maxim %d) : ", MAX);
    cin >> Mx.r;

    printf("Introdu numarul de coloane (maxim %d) : ", MAX);
    cin >> Mx.c;

    if(Mx.r > MAX || Mx.c > MAX)
    {
        Mx.r = MAX;
        Mx.c = MAX;
    }

    cout << endl;
    printf("Introdu numerele din Matricea I : \n");
    for(Mx.i = 0; Mx.i < Mx.r; Mx.i++)
    {
        for(Mx.j = 0; Mx.j < Mx.c; Mx.j++)
        {
            printf("Matrice I [%d][%d] = ", Mx.i, Mx.j);
            cin >> Mx.MX[0][Mx.i][Mx.j];
        }
    }

    cout << endl;
    printf("Introdu numerele din Matricea II : \n");
    for(Mx.i = 0; Mx.i < Mx.r; Mx.i++)
    {
        for(Mx.j = 0; Mx.j < Mx.c; Mx.j++)
        {
            printf("Matrice II [%d][%d] = ", Mx.i, Mx.j);
            cin >> Mx.MX[1][Mx.i][Mx.j];
        }
    }

    cout << endl;
    char choice;

    printf("Alege o optiune : \n");
    printf("1. Aduna Matricele\n");
    printf("2. Scade Matricele\n");
    printf("3. Inmulteste Matricele\n");

    choice = _getch();

    switch(choice)
    {
        case '1':
        {
            cout << "Adunam matricele : \n";
            for(Mx.i = 0; Mx.i < Mx.r; Mx.i++)
                for(Mx.j = 0; Mx.j < Mx.c; Mx.j++)
                    Mx.MX[2][Mx.i][Mx.j] = Mx.MX[0][Mx.i][Mx.j] + Mx.MX[1][Mx.i][Mx.j];
            break;
        }
        case '2':
        {
            cout << "Scade matricele : \n";
            for(Mx.i = 0; Mx.i < Mx.r; Mx.i++)
                for(Mx.j = 0; Mx.j < Mx.c; Mx.j++)
                    Mx.MX[2][Mx.i][Mx.j] = Mx.MX[0][Mx.i][Mx.j] - Mx.MX[1][Mx.i][Mx.j];
            break;
        }
        case '3':
        {
            cout << "Inmulteste matricele : \n";
            for(Mx.i = 0; Mx.i < Mx.r; Mx.i++)
                for(Mx.j = 0; Mx.j < Mx.c; Mx.j++)
                    Mx.MX[2][Mx.i][Mx.j] = Mx.MX[0][Mx.i][Mx.j] * Mx.MX[1][Mx.i][Mx.j];
            break;
        }
    }


    for(Mx.i = 0; Mx.i < Mx.r; Mx.i++)
    {
        for(Mx.j = 0; Mx.j < Mx.c; Mx.j++)
        {
            cout << "\t" << Mx.MX[2][Mx.i][Mx.j] << " ";
        }
        cout << endl;
    }
    return 0;
}



