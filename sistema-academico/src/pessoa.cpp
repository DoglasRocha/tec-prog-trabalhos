#include "../includes/pessoa.hpp"
#include <iostream>
#include <string>

Pessoa::Pessoa(int diaNasc_, int mesNasc_, int anoNasc_, std::string nome_)
{
    diaNasc = diaNasc_;
    mesNasc = mesNasc_;
    anoNasc = anoNasc_;
    nome = nome_;
    idade = 0;
}

Pessoa::~Pessoa() {}

Pessoa *Pessoa::setDataNasc(int diaNasc_, int mesNasc_, int anoNasc_)
{
    diaNasc = diaNasc_;
    mesNasc = mesNasc_;
    anoNasc = anoNasc_;

    return this;
}

Pessoa *Pessoa::calculaIdade(int diaAtual, int mesAtual, int anoAtual)
{
    idade = anoAtual - anoNasc;

    if (mesAtual < mesNasc)
        idade--;

    else if (mesAtual == mesNasc && diaAtual < diaNasc)
        idade--;

    return this;
}

void Pessoa::informaIdade()
{
    std::cout << nome << " tem " << idade << " anos de idade.\n"; 
}

Pessoa *Pessoa::setNome(std::string nome_)
{
    nome = nome_;

    return this;
}

std::string Pessoa::getNome()
{
    return nome;
}

