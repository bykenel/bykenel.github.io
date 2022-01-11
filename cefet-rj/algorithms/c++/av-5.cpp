// P5, Denzel Vianna de Farias (21/04/21)
#include <iostream>
#include <conio.h>
using namespace std;

enum dMes {Janeiro=1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro};

struct dData
{
    int dia;
    enum dMes mes;
    int ano;
};

string TextoMes (enum dMes mes)
{
    switch (mes)
    {
        case Janeiro : return("Janeiro");
        case Fevereiro : return("Fevereiro");
        case Marco : return("Marco");
        case Abril : return("Abril");
        case Maio : return("Maio");
        case Junho : return("Junho");
        case Julho : return("Julho");
        case Agosto : return("Agosto");
        case Setembro : return("Setembro");
        case Outubro : return("Outubro");
        case Novembro : return("Novembro");
        case Dezembro : return("Dezembro");
    }
}

int diasExistentesNoMes(struct dData data)
{
    switch (data.mes)
    {
        case Janeiro:
        case Marco:
        case Maio:
        case Julho:
        case Agosto:
        case Outubro:
        case Dezembro: return 31;
        case Abril:
        case Junho:
        case Setembro:
        case Novembro: return 30;
        case Fevereiro: if (data.ano % 4 == 0 && data.ano % 100 != 0 || data.ano % 400 == 0) return 29;
        else return 28;
        default: return 0;
    }
}

bool dataValida(struct dData data)
{
    if (data.mes >= Janeiro && data.mes <= Dezembro)
    return (data.dia >= 1 && data.dia <= diasExistentesNoMes(data));
    else return false;
}

main ()
{
    struct dData data;
    int i;
    int d;
    cout << "Forneca uma data valida...\n";
    cout << "DIA: ";
    cin>> data.dia;
    cout << "MES: ";
    cin >> i;
    data.mes = (enum dMes)i;
    cout << "ANO: ";
    cin >> data.ano;

    d = diasExistentesNoMes(data) * i;

    if (dataValida(data))
        cout << "No ano de " << data.ano << " ha " << d << " dias ate " << data.dia << "/" << TextoMes(data.mes) << "/" << data.ano << ".";
    else cout << "Data invalida!!!";

    getch();
}
