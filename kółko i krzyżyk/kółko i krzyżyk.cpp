#include <iostream>
#include "gra.h"

using namespace std;

int main()
{
    system("chcp 1250");
    system("cls");

    gra gra1;

    gra1.drukuj();

    // Ruch graczy
    while (gra1.getZwyciesca() == '-') {
        gra1.ruch();
        system("cls");
        gra1.drukuj();
    }
        
    //koniec gry
    cout << "KONIEC GRY, ZWYCIESCA TO [ " << gra1.getZwyciesca() << " ] " << endl;
}


