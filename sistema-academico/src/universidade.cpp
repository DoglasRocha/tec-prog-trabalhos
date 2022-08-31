#include "../includes/universidade.hpp"
#include <iostream>

Universidade::Universidade(std::string nome_)
{
    nome = nome_;
}

Universidade::~Universidade() {}

void Universidade::setNome(std::string nome_)
{
    nome = nome_;
}

std::string Universidade::getNome()
{
    return nome;
}

Departamento *Universidade::getDepartamento()
{
    return dpto;
}

void Universidade::setDepartamento(Departamento *departamento)
{
    dpto = departamento;
}