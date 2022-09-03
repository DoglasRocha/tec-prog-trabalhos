#pragma once
#include "pessoa.hpp"
#include <string>

class Aluno : public Pessoa
{
    private:
        int RA;

    public:
        Aluno(int diaNasc_=0, int mesNasc_=0, int anoNasc_=0, std::string nome="", int RA_=0);
        ~Aluno();
        int getRA();
        Aluno *setRA(int RA_);
};