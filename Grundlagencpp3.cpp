#include <iostream>

using namespace std;

float mittelwert(float zArray[], int zLaenge)
{
    zLaenge /= sizeof(float);
    float zCount = 0;
    for(int i = 0; i < zLaenge; i++)
    {
        zCount += zArray[i];
    }
    return zCount / zLaenge;
}

int mittelwert(int zArray[], int zLaenge)
{
    zLaenge /= sizeof(int);
    int zCount = 0;
    for(int i = 0; i < zLaenge; i++)
    {
        zCount += zArray[i];
    }
    return zCount / zLaenge;
}

int main()
{
    int array1[] = {1, 2, 3};
    float array2[] = {0.9, 2.0, 3.1};

    cout << "Der erste Mittelwert lautet: " << mittelwert(array1, sizeof(array1)) << endl;
    cout << "Der zweite Mittelwert lautet: " << mittelwert(array2, sizeof(array2)) << endl;
}
