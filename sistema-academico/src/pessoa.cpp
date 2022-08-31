#include "../includes/pessoa.hpp"
#include <iostream>
#include <string>

Pessoa::Pessoa(int diaNasc_, int mesNasc_, int anoNasc_, std::string nome_)
{
    diaNasc = diaNasc_;
    mesNasc = mesNasc_;
    anoNasc = anoNasc_;
    nome = nome_;
    univAssociado = NULL;
    idade = 0;
}

Pessoa::~Pessoa() {}

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

void Pessoa::setNome(std::string nome_)
{
    nome = nome_;
}

std::string Pessoa::getNome()
{
    return nome;
}

void Pessoa::setUniversidade(Universidade *univ)
{
    univAssociado = univ;
}

Universidade *Pessoa::getUniversidade()
{
    return univAssociado;
}

void Pessoa::ondeTrabalha()
{
    std::cout << nome << " estuda na " << univAssociado->getNome() << "\n"; 
}