#pragma once
#include <iostream>
#include <string>
#include "universidade.hpp"

class Pessoa
{
    private:
        int diaNasc, mesNasc, anoNasc, idade;
        std::string nome;
        Universidade *univAssociado;

    public:
        Pessoa(int diaNasc_=0, int mesNasc_=0, int anoNasc_=0, std::string nome_="");
        ~Pessoa();
        void setDataNasc(int diaNasc_, int mesNasc_, int anoNasc_);
        void calculaIdade(int diaAtual, int mesAtual, int anoAtual);
        void informaIdade();
        void setNome(std::string nome_="");
        std::string getNome();
        void setUniversidade(Universidade *univ);
        Universidade *getUniversidade();
        void ondeTrabalha();
};