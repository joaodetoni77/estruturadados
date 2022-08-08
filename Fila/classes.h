#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

const int TAM = 80;
using namespace std;

class departamento {
private:
    char ala [TAM] ;
public:
    void coleta_info() {
        cout << "- Informe ala em que o paciente se encontra: ";
        cin >> ala;
    }
    void mostra_info() {
        ofstream arquivo;
        arquivo.open("saida.txt",ios::app);
        arquivo << "Ala : " << ala << endl;
        arquivo.close();

        cout<<"\nAla : "<<ala;
    }
};


class doutor {
private:
    char Nome[TAM];
    char Idade[TAM];
public:
    void dados_doutor() {
        cout << "- Informe o nome do doutor: ";
        cin >> Nome;
        cout << "- Informe a Idade do doutor: ";
        cin >> Idade;
    }
    void mostra_dados_doutor() {
        ofstream arquivo;
        arquivo.open("saida.txt",ios::app);
        arquivo << "Nome do Doutor: " << Nome << endl;
        arquivo << "Idade: " << Idade << endl;
        arquivo.close();

        cout<<"\nNome do Doutor: " << Nome;
        cout<<"\nIdade: " << Idade;
    }
};

class Paciente {
private:
    char Nome[TAM];
    char num [TAM];
public:
    void coleta_info() {
        ofstream arquivo;
        cout<<"- Informe nome do paciente: ";
        cin>>Nome;
        fflush(stdin);
        cout<<"- Informe numero do quarto: ";
        cin>>num;
    }
    void mostra_info() {
        ofstream arquivo;
        arquivo.open("saida.txt",ios::app);
        arquivo << "Nome paciente: " << Nome << endl;
        arquivo << "Numero do Quarto: " << num << endl;
        arquivo.close();
        cout << "\nNome do paciente: " << Nome;
        cout << "\nNumero do Quarto: " << num;
    }
};

class qnt {
private:
    int dias;
    Paciente pat;
    doutor doc;
    departamento dept;
public:
    void coleta_info() {
        pat.coleta_info();
        dept.coleta_info();
        doc.dados_doutor();
        cout << "- Informe a quantidade de dias de sintomas: ";
        cin >> dias;
    }
    void mostra_info() {
        ofstream arquivo;
        pat.mostra_info();
        dept.mostra_info();
        doc.mostra_dados_doutor();
        arquivo.open("saida.txt",ios::app);
        arquivo << "Dias de sintomas: " << dias << endl;
        arquivo.close();
        cout << "\nDias de sintomas: "<< dias << endl;
    }
};


#endif