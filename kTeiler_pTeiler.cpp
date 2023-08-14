#include <stdio.h>
#include <stdlib.h>

/*
    PVL1 - Aufgabe 5
    Kai Martin Tüllmann (MNR: 30257832)
    16/05/2022
*/

int main(void)
{
    //ConsoleSelect: Aufgabe 5.1/.2, Aufgabe 5.3 und Exit
    while(1)
    {
    startenProgramme();
    system("cls");
    }
    return 0;
}

//Anfragen & Auslesen der UserEingabe
int zahlAuslesen()
{
    int z;

    printf("\nGeben Sie eine Ganzzahl groesser 1 ein: ");
    scanf("%d", &z);
    return z;
}

//Kleinsten Primteiler einer gegebenen Zahl(z) errechnen
int kTeiler(int z)
{
    if(z % 2 == 0)
        return 2;

    for(int i = 3, skipCount = 0; i * i <= z; i += 2, skipCount++)
    {
        if (z % i == 0)
            return i;

        if(skipCount == 2)
        {
            skipCount = 0;
            i += 2;
        }
    }

    return z;
}

//Aufgabe 5.1/.2
void kleinsterTeiler(int z)
{
    if(z <= 1)
    {
        printf("Invalid Input!");
        return;
    }

    printf("Der kleinste Primteiler der Zahl ist: %d\n", kTeiler(z));
}

//Aufgabe 5.3
void prim(int z)
{
    int zDiv = kTeiler(z);

    if(z <= 1)
    {
        printf("Invalid Input!");
        return;
    }

    printf("%d = %d", z, zDiv);

    while(z > zDiv)
    {
        z /= zDiv;
        printf(" * %d", kTeiler(z));
    }

    return;
}

//SelectionScreen
void startenProgramme()
{
    int oSelect, z;

    printf("Waehlen Sie eine der 3 Optionen (durch Eingabe der Zahlen 1-3):\n#1   kleinsterTeiler(int)   [Aufgabe 5.1/.2]\n#2   prim(int)              [Aufgabe 5.3]\n#3   Exit\n\n");
    scanf("%d", &oSelect);

    switch(oSelect)
    {
        case 1:
            z = zahlAuslesen();
            kleinsterTeiler(z);
            sleep(3);
            break;
        case 2:
            z = zahlAuslesen();
            prim(z);
            sleep(3);
            break;
        case 3:
            exit(0);
        default:
            return;
    }
}
