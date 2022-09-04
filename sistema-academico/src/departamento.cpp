#include "../includes/departamento.hpp"
#include "../includes/universidade.hpp"
#include "../includes/disciplina.hpp"
#include <string>
#include <iostream>

Departamento::Departamento(std::string nome_)
{
    nome = nome_;
    univ = NULL;
    primeiraDisciplina = ultimaDisciplina = NULL;
}

Departamento::~Departamento() 
{
    primeiraDisciplina = ultimaDisciplina = NULL;    
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
    if (primeiraDisciplina == NULL)
        primeiraDisciplina = ultimaDisciplina = disciplina;

    else
        disciplina->prev = ultimaDisciplina,
        ultimaDisciplina->next = disciplina, 
        ultimaDisciplina = disciplina;

    return this;
}

void Departamento::imprimeDisciplinas()
{
    Disciplina *aux;
    for (aux = primeiraDisciplina; aux != NULL; aux = aux->next)
        std::cout << "A disciplina " << aux->getNome() << " pertence ao departamento " << nome << "\n";
}
