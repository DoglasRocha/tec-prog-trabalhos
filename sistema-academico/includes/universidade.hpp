#pragma once
#include <iostream>
#include "departamento.hpp"

class Universidade
{
    private:
        std::string nome;
        Departamento *dpto;

    public:
        Universidade(std::string nome_="");
        ~Universidade();
        void setNome(std::string nome_="");
        std::string getNome();
        Departamento *getDepartamento();
        void setDepartamento(Departamento *departamento);
    
};