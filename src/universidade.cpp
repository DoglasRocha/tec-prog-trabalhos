#include "../includes/universidade.hpp"
#include "../includes/departamento.hpp"
#include "../linked-list/src/linked-list.cpp"
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
    dptos.append(departamento);
    departamento->setUniversidade(this);

    return this;
}

void Universidade::imprimeDepartamentos()
{
    for (int i = 0, l = dptos.getLength(); i < l; i++)
        std::cout << "O " << dptos[i]->getNome() << " pertence a "
                  << nome << std::endl;
}

LinkedList<Departamento *> Universidade::getDptos() {
    return dptos;
}
