#include "../includes/professor.hpp"
#include <string>

Professor::Professor(int diaNasc_, int mesNasc_, int anoNasc_, std::string nome_)
: Pessoa(diaNasc_, mesNasc_, anoNasc_, nome_)
{
    univAssociado = NULL;
    dptoAssociado = NULL;
}

Professor::~Professor() {
    univAssociado = NULL;
    dptoAssociado = NULL;
}

Professor *Professor::setUniversidade(Universidade *univ)
{
    univAssociado = univ;
    return this;
}

Universidade *Professor::getUniversidade()
{
    return univAssociado;
}

void Professor::ondeTrabalha()
{
    std::cout << nome << " trabalha na " << univAssociado->getNome() << " no " << dptoAssociado->getNome() << "\n"; 
}

Departamento *Professor::getDepartamento()
{
    return dptoAssociado;
}

Professor *Professor::setDepartamento(Departamento *dpto)
{
    dptoAssociado = dpto;

    return this;
}