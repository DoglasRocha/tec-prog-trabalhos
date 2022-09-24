#include "../includes/departamento.hpp"
#include "../includes/universidade.hpp"
#include "../includes/disciplina.hpp"
#include "../linked-list/includes/linked-list.hpp"
#include <string>
#include <iostream>

Departamento::Departamento(std::string nome_)
{
    nome = nome_; 
    univ = 0;
}

Departamento::~Departamento() 
{
      
}

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

Departamento *Departamento::addDisciplina(Disciplina *disciplina)
{
    ListaDisciplinas.append(disciplina);

    return this;
}

void Departamento::imprimeDisciplinas()
{
    for (int i = 0, l = ListaDisciplinas.getLength(); i < l; i++)
        std::cout << "A disciplina " << ListaDisciplinas[i]->getNome() << " pertence ao departamento " << nome << "\n";
}
