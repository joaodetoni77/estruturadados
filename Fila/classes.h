#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

const int TAM = 80;
using namespace std;

class departamento
{
private:
    char ala [TAM] ;
public:
    void coleta_info()
    {
        cout<<"\nInforme ala em que o paciente se encontra : ";
        cin>>ala;
    }
    void mostra_info()
    {
        ofstream arquivo;
        arquivo.open("saida.txt",ios::app);
        arquivo << "\nAla : " << ala << endl;
        arquivo.close();

        cout<<"\nAla : "<<ala;
    }
};


class doutor
{
private:
    char Nome[TAM];
    char Idade[TAM];
public:
    void dados_doutor()
    {
        cout<<"\nInforme o nome do doutor : ";
        cin>> Nome;
        cout<<"\nInforme a Idade do doutor : ";
        cin>>Idade;
    }
    void mostra_dados_doutor()
    {
        ofstream arquivo;
        arquivo.open("saida.txt",ios::app);
        arquivo << "\nNome do Doutor : " << Nome << endl;
        arquivo << "\nIdade: " << Idade << endl;
        arquivo.close();

        cout<<"\nNome do Doutor : "<<Nome;
        cout<<"\nIdade: "<<Idade;
    }
};

class Paciente
{
private:
    char Nome[TAM];
    char num [TAM];
public:
    void coleta_info()
    {
        ofstream arquivo;
        cout<<"\nInforme nome do paciente : ";
        cin>>Nome;
        cout<<"\nInforme numero do quarto : ";
        cin>>num;
    }
    void mostra_info()
    {
        ofstream arquivo;
        arquivo.open("saida.txt",ios::app);
        arquivo << "\nNome paciente : " << Nome << endl;
        arquivo << "\nNumero do Quarto : " << num << endl;
        arquivo.close();

        cout<<"\nNome paciente : "<<Nome;
        cout<<"\nNumero do Quarto : "<<num;
    }
};

class qnt
{
private:
    int dias;
    Paciente pat;
    doutor doc;
    departamento dept;
public:
    void coleta_info()
    {
        pat.coleta_info();
        dept.coleta_info();
        doc.dados_doutor();
        cout<<"\nInforme a quantidade de dias de sintomas: ";
        cin>>dias;
    }
    void mostra_info()
    {
        ofstream arquivo;
        pat.mostra_info();
        dept.mostra_info();
        doc.mostra_dados_doutor();
        arquivo.open("saida.txt",ios::app);
        arquivo << "\nDias de sintomas" << dias << endl;
        arquivo.close();
        cout<<"\nDias de sintomas: "<< dias << endl;
    }
};


#endif // CLASSES_H_INCLUDED
