// P4, Denzel Vianna de Farias (10/03/21)
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

main()
{
int n, y, j, qp, i;
 cout << "Digite a quantidade de numeros que dejesa armazernar: ";
 cin >> n;

int x[n];

y = 0;
while (n > y)
{
    cout << "Numero natural " << y+1 << ":\n";
    cin >> x[y];

    if (x[y]>=0)
        y++;
}

y = 0;
qp = 0;
while (qp < n)
{
    qp = y*y;
    y++;
}

i = qp;
j = qp;
int m[i][j];
while (y > i)
{
    j = 0;
    while (y > j)
    {
        if (y==n)
        {
            i = 0;
        }
       m[i][j] = x[y];
       cout << "M[" << i << "]" << j << "] = " << m[i][j] << " \n";
    }
}
getch();
}

