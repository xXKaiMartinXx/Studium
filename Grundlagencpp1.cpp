#include <iostream>
#include <string>

using namespace std;

void pruefeAlter(int &zAlter)
{
if(zAlter < 0)
    zAlter *= -1;
return;
}

int main()
{
    string zBenutzer;
    int zAlter;

    cout << "Geben Sie zuerst einen Benutzernamen und dann ein Alter an:" << endl;

    cin >> zBenutzer;
    cin >> zAlter;

    pruefeAlter(zAlter);

    cout << "Benutzername: " << zBenutzer << endl << "Alter: " << zAlter << endl;

    return 0;
}
