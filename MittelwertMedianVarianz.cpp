#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define __DEBUG_AUSGABEN__

//Elemente meiner Liste
typedef struct _Element
{
    int z;
    struct _Element *naechster;
} _Element;

//Head meiner Liste (auch ein Element)
typedef struct
{
    _Element *anfang;
} _Anfang;



//Deklaration der Funktionen zur berechnung der notwendigen Werte
float mittelwert(_Anfang *anfangL);
float varianz(_Anfang *anfangL, float m);
float median(_Anfang *anfangL);



int main(void)
{
    int zahl = 0, stop = 0;

    _Anfang Liste;
    _Element *e;

    printf("Bitte geben Sie die Daten des Datensatzes ein:\n");
    //Erstes Element "manuell" anlegen
    scanf("%d", &zahl);
    e = malloc(sizeof(_Element));
    e -> z = zahl;
    e -> naechster = NULL;
    Liste.anfang = e;   //Element als "head" setzen

    while(stop != 1)
    {
        if(scanf("%*[^b0-9]%d", &zahl)) //Nur Zahlen und "b" auslesen
        {
            e = malloc(sizeof(_Element));
            e -> z = zahl;
            e -> naechster = NULL;
            einfuegen(e, &Liste);
        }
        else
        {
            bubbleSort(&Liste); //Sortieren NOTWENIG VOR berechnung des MEDIAN

            float mit = mittelwert(&Liste),
                  var = varianz(&Liste, mit),
                  med = median(&Liste);

            #ifdef __DEBUG_AUSGABEN__
            printf("\n");
            ausgeben(&Liste);
            printf("\n");
            #endif

            printf("\nMittelwert: %9.2f", mit);
            printf("\nVarianz: %12.2f", var);
            printf("\nMedian: %13.2f", med);

            stop = 1;
        }
    }
    return 0;
}



//Fügt Zahlen in die Liste ein
void einfuegen(_Element *neu, _Anfang *anfangL)
{
    _Element *temp;
    temp = anfangL -> anfang;

    while(temp -> naechster != NULL)
    {
        temp = temp -> naechster;
    }
    temp -> naechster = neu;
}

//Gibt angegebene Liste aus
void ausgeben(_Anfang *anfangL)
{
    _Element *temp;
    temp = anfangL -> anfang;

    while(temp != NULL)
    {
        printf("%d", temp -> z);
        temp = temp -> naechster;
        if(temp != NULL)
            printf(", ");
    }
}

//Sortiert angegebene Liste
void bubbleSort(_Anfang *anfangL)
{
    _Element *temp1, *temp2;

    int reSort = 1;

    while(reSort == 1)
    {
        reSort = 0;
        temp1 = anfangL -> anfang;
        temp2 = temp1 -> naechster;

        while(temp1 -> naechster != NULL)
        {
            if(temp1 -> z > temp2 -> z)
            {
                int z1 = temp1 -> z;
                temp1 -> z = temp2 -> z;
                temp2 -> z = z1;
                reSort = 1;
            }
            temp1 = temp2;
            temp2 = temp2 -> naechster;
        }
    }
}



//Berechnet den Mittelwert aller Werte der Liste
float mittelwert(_Anfang *anfangL)
{
    float zZahl = 0, i = 0;

    _Element *temp;
    temp = anfangL -> anfang;
    while(temp != NULL)
    {
        zZahl += temp -> z;
        temp = temp -> naechster;
        i++;
    }
    return zZahl/i;
}

//Berechnet die Varianz aller Werte der Liste
float varianz(_Anfang *anfangL, float m)
{
    float zZahl = 0, i = 0;

    _Element *temp;
    temp = anfangL -> anfang;
    while(temp != NULL)
    {
        zZahl += pow(temp -> z - m, 2);
        temp = temp -> naechster;
        i++;
    }

    return zZahl / (i-1);
}

//Berechnet den Median der Werte in der Liste (Anwendung von BUBBLESORT VOR NUTZUNG NOTWENDIG!)
float median(_Anfang *anfangL)
{
    _Element *temp;
    temp = anfangL -> anfang;
    int i = 0;

    while(temp != NULL) //Anzahl der ListenElemente überprüfen
    {
        temp = temp -> naechster;
        i++;
    }

    temp = anfangL -> anfang;

    if(i % 2 == 0)  //Fallunterscheidung (Index gerade oder ungerade)
    {
        for(int n = 0; n != i/2-1; n++)
        {
            temp = temp -> naechster;
        }
        int zahl = temp -> z; //linke/obere Mitte speichern (da eine gerade Menge an Werten keinen mittigen Wert hat)
        temp = temp -> naechster;
        zahl += temp -> z;    //rechte/untere Mitte addieren
        return zahl/2.0;
    }
    else
    {
        for(int n = 0; n != i/2; n++)
        {
            temp = temp -> naechster;
        }
        return temp -> z;
    }
}
