#include "../includes/departamento.hpp"
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

void Departamento::setNome(std::string nome_)
{
    nome = nome_;
}
