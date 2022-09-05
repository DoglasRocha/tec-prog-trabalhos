#pragma once
#include "pessoa.hpp"
#include <iostream>

class Universidade;
class Departamento;

class Professor : public Pessoa
{
    private:
        Universidade *univAssociado;
        Departamento *dptoAssociado;

    public:
        Professor(int diaNasc_=0, int mesNasc_=0, int anoNasc_=0, std::string nome_="");
        ~Professor();
        Professor *setUniversidade(Universidade *univ);
        Universidade *getUniversidade();
        void ondeTrabalha();
        Departamento *getDepartamento();
        Professor *setDepartamento(Departamento *dpto);
};
