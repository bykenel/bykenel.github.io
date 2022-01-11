// AV1, Denzel Vianna de Farias (18/11/20)
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

float conversorFtoC (float fah,float cel)
{
cel = 5*(fah-32)/9;
return cel;
}

float conversorCtoK (float cel,float kel)
{
kel = cel+273,15;
return kel;
}

float FtoC (float fah,float cel)
{
cout << "Digite a temperatura em Fahrenheit: ";
cin >> fah;
cel = conversorFtoC (fah,cel);
cout << "Temperatura em Celsius =  " << cel << "\n";
getch();
}

float CtoK (float cel,float kel)
{
cout << "Digite a temperatura em Celsius: ";
cin >> cel;
kel = conversorCtoK (cel,kel);
cout << "Temperatura em Kelvin = " << kel << "\n";
getch();
}

main()
{
//FtoK
float fah,cel,kel;
cout << "Digite a temperatura em Fahrenheit: ";
cin >> fah;
cel = conversorFtoC (fah,cel);
kel = conversorCtoK (cel,kel);
cout << "Temperatura em Celsius = " << cel << "\n";
cout << "Temperatura em Kelvin = " << kel << "\n";
getch();
}
