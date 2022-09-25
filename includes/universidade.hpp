#pragma once
#include <iostream>
#include <list>
#include "../linked-list/includes/linked-list.hpp"

class Departamento;
class ListaDepartamentos;

class Universidade
{
    private:
        std::string nome;
        ListaDepartamentos *dptos;

    public:
        Universidade(std::string nome_="");
        ~Universidade();
        Universidade *setNome(std::string nome_="");
        std::string getNome();
        Universidade *setDepartamento(Departamento *departamento);
        ListaDepartamentos *getDptos();
        void imprimeDepartamentos();
};
