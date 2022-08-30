#include "../includes/pessoa.hpp"
#include <iostream>
#include <string>

Pessoa::Pessoa(int diaNasc_, int mesNasc_, int anoNasc_, std::string nome_)
{
    diaNasc = diaNasc_;
    mesNasc = mesNasc_;
    anoNasc = anoNasc_;
    idade = 0;
    nome = nome_;
    calculaIdade(30, 8, 2022);
}

Pessoa::~Pessoa()
{

}

void Pessoa::setDataNasc(int diaNasc_, int mesNasc_, int anoNasc_)
{
    diaNasc = diaNasc_;
    mesNasc = mesNasc_;
    anoNasc = anoNasc_;
}

void Pessoa::calculaIdade(int diaAtual, int mesAtual, int anoAtual)
{
    idade = anoAtual - anoNasc;

    if (mesAtual < mesNasc)
        idade--;

    else if (mesAtual == mesNasc && diaAtual < diaNasc)
        idade--;
}

void Pessoa::informaIdade()
{
    std::cout << nome << " tem " << idade << " anos de idade.\n"; 
}