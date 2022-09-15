#include "../includes/aluno.hpp"
#include "../includes/pessoa.hpp"
#include "../includes/universidade.hpp"
#include "../includes/departamento.hpp"
#include <string>

Aluno::Aluno(int diaNasc_, int mesNasc_, int anoNasc_, std::string nome_, int RA_)
: Pessoa(diaNasc_, mesNasc_, anoNasc_, nome_)
{
    RA = RA_;
    univAssociado = nullptr;
    dptoAssociado = nullptr;
}

Aluno::~Aluno() 
{
    univAssociado = nullptr;
    dptoAssociado = nullptr;
}

int Aluno::getRA()
{
    return RA;
}

Aluno *Aluno::setRA(int RA_)
{
    RA = RA_;
    return this;
}

Universidade *Aluno::getUnivAssociado()
{
    return univAssociado;
}

Aluno *Aluno::setUnivAssociado(Universidade *univ)
{
    univAssociado = univ;

    return this;
}

Departamento *Aluno::getDptoAssociado()
{
    return dptoAssociado;
}

Aluno *Aluno::setDptoAssociado(Departamento *dpto)
{
    dptoAssociado = dpto;

    return this;
}

void Aluno::ondeEstuda()
{
    std::cout << nome << " estuda na " << univAssociado->getNome() << " no " << dptoAssociado->getNome() << " e tem o RA " << RA << "\n";
}