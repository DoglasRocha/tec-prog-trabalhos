#include "../includes/departamento.hpp"
#include "../includes/universidade.hpp"
#include <string>

Departamento::Departamento(std::string nome_)
{
    nome = nome_;
}

Departamento::~Departamento() {}

std::string Departamento::getNome()
{
    return nome;
}

Departamento *Departamento::setNome(std::string nome_)
{
    nome = nome_;
    return this;
}

Universidade *Departamento::getUniversidade()
{
    return univ;
}

Departamento *Departamento::setUniversidade(Universidade *universidade)
{
    univ = universidade;
    return this;
}
