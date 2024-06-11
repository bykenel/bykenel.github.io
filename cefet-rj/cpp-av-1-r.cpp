// Recuperação T1, Denzel Vianna de Farias (16/12/20)
#include<conio.h>
#include<stdio.h>
#include <iostream>
using namespace std;

const int pedra = 0;
const int papel = 5;
const int tesoura = 2;

int pedraPapelTesoura (int mao1, int mao2)
{
int resultado;
if (mao1 == 0 && mao2 == 0 || mao1 == 5 && mao2 == 5 || mao1 == 2 && mao2 == 2)
    resultado = 0;
    else {
        if (mao1 == 0 && mao2 == 2 || mao1 == 2 && mao2 == 5 || mao1 == 5 && mao2 == 0)
            resultado = 1;
            else{
                if (mao1 == 2 && mao2 == 0 || mao1 == 5 && mao2 == 2 || mao1 == 0 && mao2 == 5)
                resultado = 2;
                }
        }
  return resultado;
}

main()
{
 int mao1, mao2, resultado;
 cout << "*******************************\n";
 cout << "* JOGO PEDRA, PAPEL E TESOURA *\n";
 cout << "*******************************\n\n";
 cout << "SIMBOLOS DO JOGO:\n";
 cout << "0 --> PEDRA\n";
 cout << "2 --> TESOURA\n";
 cout << "5 --> PAPEL\n\n";
 cout << "INSIRA A MAO DO JOGAROR 1: ";
 cin >> mao1;
 cout << "INSIRA A MAO DO JOGAROR 2: ";
 cin >> mao2;

  if (pedraPapelTesoura(mao1, mao2) == 0)
    cout << "EMPATE!";
    else {
        if (pedraPapelTesoura(mao1, mao2) == 1)
        cout << "O JOGADOR 1 FOI O VENCEDOR!";
         else {
            if (pedraPapelTesoura(mao1, mao2) == 2)
            cout << "O JOGADOR 2 FOI O VENCEDOR!";
            else {
                if (!mao1 == 0 || !mao1 == 2 || !mao1 == 5 || !mao2 == 0 || !mao2 == 2 || !mao2 == 5)
                cout << "ERRO!";
            }
        }
    }
 getch();
}

