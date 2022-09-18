#pragma once
#include <iostream>
#include <list>
#include "../linked-list/includes/linked-list.hpp"

class Departamento;

class Universidade
{
    private:
        std::string nome;
        LinkedList<Departamento *> dptos;

    public:
        Universidade(std::string nome_="");
        ~Universidade();
        Universidade *setNome(std::string nome_="");
        std::string getNome();
        Universidade *setDepartamento(Departamento *departamento);
        LinkedList<Departamento *> getDptos();
        void imprimeDepartamentos();
};
