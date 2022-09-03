#include "../includes/disciplina.hpp"
#include "../includes/departamento.hpp"
#include <string>

Disciplina::Disciplina(std::string nome_, std::string areaConhecimento_)
{
    nome = nome_;
    areaConhecimento = areaConhecimento_;
    dptoAssociado = NULL;
    next = NULL;
}

Disciplina::~Disciplina() {}

std::string Disciplina::getNome()
{
    return nome;
}

Disciplina *Disciplina::setNome(std::string nome_)
{
    nome = nome_;

    return this;
}

std::string Disciplina::getAreaConhecimento()
{
    return areaConhecimento;
}

Disciplina *Disciplina::setAreaConhecimento(std::string areaConhecimento_)
{
    areaConhecimento = areaConhecimento_;

    return this;
}

Departamento *Disciplina::getDptoAssociado()
{
    return dptoAssociado;
}

Disciplina *Disciplina::setDptoAssociado(Departamento *departamento)
{
    dptoAssociado = departamento;
    dptoAssociado->addDisciplina(this);
    
    return this;
}