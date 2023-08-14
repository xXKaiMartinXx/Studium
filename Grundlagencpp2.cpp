#include <iostream>

using namespace std;

template<typename T>
double mittelwert(T zArray[], int zLaenge)
{
    T zCount = 0;
    for(int i = 0; i < zLaenge; i++)
    {
        zCount += zArray[i];
    }
    return (double)zCount / zLaenge;
}

int main()
{
    cout << "Geben Sie die Groesse des gewuenschten Arrays an:" << endl;
    int zLaenge;
    cin >> zLaenge;
    cout << "Geben Sie nun die Werte des Arrays ein:" << endl;
    double *zArrayIn = new double[zLaenge];
    for(int i = 0; i < zLaenge; i++)
    {
        cin >> zArrayIn[i];
    }
    cout << "Der Mittelwert Ihrer Werte lautet: " << mittelwert(zArrayIn, zLaenge) << endl;
    return 0;
}
