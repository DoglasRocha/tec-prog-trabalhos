#pragma once
#include "universidade.hpp"
#include "pessoa.hpp"

class Principal
{
    private:
        Pessoa Doglas;
        Universidade UTFPR;
        int diaAtual, mesAtual, anoAtual;
    public:
        Principal();
        ~Principal();
        void executar();
};
