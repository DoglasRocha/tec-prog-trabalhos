#include "../includes/universidade.hpp"
#include <iostream>
#include <list>

Universidade::Universidade(std::string nome_)
{
    nome = nome_;
}

Universidade::~Universidade() {}

Universidade *Universidade::setNome(std::string nome_)
{
    nome = nome_;

    return this;
}

std::string Universidade::getNome()
{
    return nome;
}

Universidade *Universidade::setDepartamento(Departamento *departamento)
{
    dptos.push_back(departamento);

    return this;
}

void Universidade::imprimeDepartamentos()
{
    std::list<Departamento *>::iterator iterator;

    for (iterator = dptos.begin(); iterator != dptos.end(); iterator++)
        std::cout << (*iterator)->getNome() << "\n";
}