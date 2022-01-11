// AV2, Denzel Vianna de Farias (09/12/20)
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

bool digito(char carac)
{
  return (carac >= '0' && carac <= '9');
}

bool letra(char carac)
{
return ((carac >= 'A' && carac <= 'Z') || (carac >= 'a' && carac <= 'z'));
}

bool digitoPar(char carac)
{
  bool resultado = 0;
  if (carac == '0' || carac == '2' || carac == '4' || carac == '6' || carac == '8')
      resultado = 1;
  return resultado;
}

bool vogal(char carac)
{
   bool resultado = 0;
  if (carac == 'A' || carac == 'E' || carac == 'I' || carac == 'O' || carac == 'U' || carac == 'a' || carac == 'e' || carac == 'i' || carac == 'o' || carac == 'u')
        resultado = 1;
  return resultado;
}

bool maiuscula(char carac)
{
  bool resultado = 0;
  if (carac >= 'A' && carac <= 'Z')
       resultado = 1;
  return resultado;
}

main()
{
char carac;
cout << "Digite um caractere: ";
cin >> carac;
    if (letra(carac) && vogal(carac) == 1 && maiuscula(carac) == 0)
    cout << "O caractere fornecido e vogal minuscula.";
    else {
        if (letra(carac) && vogal(carac) == 1 && maiuscula(carac) == 1)
        cout << "O caractere fornecido e vogal maiuscula.";
            else {
                if (letra(carac) && vogal(carac) == 0 && maiuscula(carac) == 0)
                cout << "O caractere fornecido e consoante minuscula.";
                    else {
                        if (letra(carac) && vogal(carac) == 0 && maiuscula(carac) == 1)
                        cout << "O caractere fornecido e consoante maiuscula.";
                            else {
                                if (digito(carac) && digitoPar(carac) == 1)
                                cout << "O caractere fornecido e digito par.";
                                    else {
                                        if (digito(carac) && digitoPar(carac) == 0)
                                        cout << "O caractere fornecido e digito impar.";
                                            else {
                                                if (!digito(carac) && !letra(carac))
                                                cout << "O caractere fornecido nao e nem letra, nem digito.";
                                                 }
                                    }
                            }

                    }
            }
    }
getch();
}
