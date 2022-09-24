#include "../includes/disciplina.hpp"
#include "../includes/departamento.hpp"
#include "../includes/aluno.hpp"
#include "../linked-list/includes/linked-list.hpp"
#include "../includes/ficha_aluno.hpp"
#include <string>

Disciplina::Disciplina(std::string nome_, std::string areaConhecimento_)
{
    nome = nome_;
    areaConhecimento = areaConhecimento_;
    dptoAssociado = 0;
    next = prev = 0;
    numeroMaxAlunos = 45;
}

Disciplina::~Disciplina() 
{

}

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

void Disciplina::imprimeAlunos()
{
    for (int i = 0, l = listaAlunos.getLength(); i < l; i++)
    {
        std::cout << "O aluno " << listaAlunos[i]->getAluno()->getNome() << " está matriculado na disciplina " << nome << "\n";
    }

}

Disciplina *Disciplina::addAluno(Aluno *novoAluno)
{
    int tamComparacao, compNomes, qtdAlunos = listaAlunos.getLength();
    FichaAluno *novaFichaAluno = new FichaAluno(novoAluno);

    if (qtdAlunos == numeroMaxAlunos)
    {
        std::cout << "Disciplina lotada\n";
        return this;
    }

    if (qtdAlunos == 0)
        listaAlunos.append(novaFichaAluno);
    
    else
    {
        for (int i = 0, qtdAlunos = listaAlunos.getLength(); i < qtdAlunos; i++)
        {
            tamComparacao = 1;
            compNomes = listaAlunos[i]->getAluno()->getNome().compare(0, tamComparacao, 
                novoAluno->getNome(), 0, tamComparacao);

            while (compNomes == 0)
                tamComparacao++,
                compNomes = listaAlunos[i]->getAluno()->getNome().compare(0, tamComparacao, 
                    novoAluno->getNome(), 0, tamComparacao);

            if (compNomes > 0)
            {
                listaAlunos.insert(novaFichaAluno, i);

                return this;
            }
        }

        listaAlunos.append(novaFichaAluno);
    }

    return this;
}

Disciplina *Disciplina::removerAluno(Aluno *aluno)
{
    for (int i = 0, l = listaAlunos.getLength(); i < l; i++)
    {
        if (aluno == listaAlunos[i]->getAluno())
        {
            listaAlunos.remove(i);
            return this;
        }
    }

    std::cout << "Aluno não encontrado\n";
    return this;
} 
