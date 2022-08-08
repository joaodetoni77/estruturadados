#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;

int main()
{
    qnt a1;
    string elementos;

    ofstream arquivo;

    arquivo.open("saida.txt");
    arquivo << "Dados inseridos: \n";
    arquivo.close();

    while(true)
    {
        cout<<"\nEntre com as informacoes do paciente e do doutor\n ";
        a1.coleta_info();

        a1.mostra_info();
        arquivo.open("saida.txt",ios::app);
        arquivo << "\n-----------------------------------------------\n";
        cout<<"\nPara sair digite (0)\nPara continuar digite (1)\n ";
        cin >> elementos;
        arquivo.close();

        if(elementos == "0")
            break;
    }

    return 0;
}
