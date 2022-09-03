#include "../includes/aluno.hpp"
#include "../includes/pessoa.hpp"
#include <string>

Aluno::Aluno(int diaNasc_, int mesNasc_, int anoNasc_, std::string nome_, int RA_)
: Pessoa(diaNasc_, mesNasc_, anoNasc_, nome_)
{
    RA = RA_;
}

Aluno::~Aluno() {}

int Aluno::getRA()
{
    return RA;
}

Aluno *Aluno::setRA(int RA_)
{
    RA = RA_;
    return this;
}