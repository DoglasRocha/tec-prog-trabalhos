#pragma once
#include <iostream>
#include <string>

class Universidade;

class Pessoa
{
    protected:
        int diaNasc, mesNasc, anoNasc, idade;
        std::string nome;

    public:
        Pessoa(int diaNasc_=0, int mesNasc_=0, int anoNasc_=0, std::string nome_="");
        ~Pessoa();
        Pessoa *setDataNasc(int diaNasc_, int mesNasc_, int anoNasc_);
        Pessoa *calculaIdade(int diaAtual, int mesAtual, int anoAtual);
        void informaIdade();
        Pessoa *setNome(std::string nome_="");
        std::string getNome();
};