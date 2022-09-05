#pragma once
#include <iostream>
#include <list>

class Departamento;

class Universidade
{
    private:
        std::string nome;
        std::list<Departamento *>dptos;

    public:
        Universidade(std::string nome_="");
        ~Universidade();
        Universidade *setNome(std::string nome_="");
        std::string getNome();
        Universidade *setDepartamento(Departamento *departamento);
        void imprimeDepartamentos();
};
