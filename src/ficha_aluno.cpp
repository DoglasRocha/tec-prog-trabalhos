#include "../includes/ficha_aluno.hpp"
#include "../includes/aluno.hpp"
#include <iostream>

FichaAluno::FichaAluno(Aluno *ptrAluno_)
{
	ptrAluno = ptrAluno_;
	notas[0] = 0, notas[1]= 0;
	faltas = 0;
}

FichaAluno::~FichaAluno()
{

}

Aluno *FichaAluno::getAluno()
{
  	return ptrAluno;
}

FichaAluno *FichaAluno::setAluno(Aluno *ptrAluno_)
{
  	ptrAluno = ptrAluno_;

  	return this;
}

void FichaAluno::imprimeNotas()
{
  	for (int i = 1; i <= 2; i++)
    	std::cout << "Nota da " << i << "ª parcial do aluno "
            	  << ptrAluno->getNome() << ": " << notas[0]
              	  << std::endl;

}

FichaAluno *FichaAluno::setNota(float nota, int numParcial)
{
  	if (numParcial != 1 && numParcial != 2)
    	std::cout << "Número da parcial inválida." << std::endl;

  	else
    	notas[numParcial] = nota;

  	return this;
}

float FichaAluno::getNota(int numParcial)
{
    if (numParcial != 0 && numParcial != 1)
        return 0;

    return notas[numParcial];
}

int FichaAluno::getFaltas()
{
  	return faltas;
}

FichaAluno *FichaAluno::addFaltas(int faltas_)
{
  	if (faltas < 1)
    	std::cout << "Faltas não adicionadas" << std::endl;

  	else
    	faltas += faltas_;

	return this;
}
