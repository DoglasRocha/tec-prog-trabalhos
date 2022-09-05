#pragma once
#include "pessoa.hpp"
#include <string>

class Universidade;
class Departamento;

class Aluno : public Pessoa
{
    private:
        int RA;
        Universidade *univAssociado;
        Departamento *dptoAssociado;

    public:
        Aluno *next;
        Aluno *prev;
        
        Aluno(int diaNasc_=0, int mesNasc_=0, int anoNasc_=0, std::string nome="", int RA_=0);
        ~Aluno();
        int getRA();
        Aluno *setRA(int RA_);
        Universidade *getUnivAssociado();
        Aluno *setUnivAssociado(Universidade *univ);
        Departamento *getDptoAssociado();
        Aluno *setDptoAssociado(Departamento *departamento);
        void ondeEstuda();
};