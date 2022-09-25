#include "../includes/universidade.hpp"
#include "../includes/departamento.hpp"
#include "../includes/lista_departamentos.hpp"
#include <iostream>
#include <list>

Universidade::Universidade(std::string nome_)
{
    nome = nome_;
    dptos = new ListaDepartamentos();
}

Universidade::~Universidade()
{
    delete dptos;
}

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
    dptos->append(departamento);
    departamento->setUniversidade(this);

    return this;
}

void Universidade::imprimeDepartamentos()
{
    dptos->imprimeDptosEUniv();
}

ListaDepartamentos *Universidade::getDptos() {
    return dptos;
}
