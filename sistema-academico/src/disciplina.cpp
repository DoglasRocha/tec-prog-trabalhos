#include "../includes/disciplina.hpp"
#include "../includes/departamento.hpp"
#include "../includes/aluno.hpp"
#include <string>

Disciplina::Disciplina(std::string nome_, std::string areaConhecimento_)
{
    nome = nome_;
    areaConhecimento = areaConhecimento_;
    dptoAssociado = NULL;
    next = prev = NULL;
    primeiroAluno = ultimoAluno = NULL;
    numeroMaxAlunos = 45;
    countAlunos = 0;
}

Disciplina::~Disciplina() 
{
    primeiroAluno = ultimoAluno = NULL;
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
    for (Aluno *aux = primeiroAluno; aux != NULL; aux = aux->next)
        std::cout << "O aluno " << aux->getNome() << " está matriculado na disciplina " << nome << "\n";

}

Disciplina *Disciplina::addAluno(Aluno *novoAluno)
{
    int tamComparacao, compNomes;

    if (countAlunos == numeroMaxAlunos)
    {
        std::cout << "Disciplina lotada\n";
        return this;
    }

    if (countAlunos == 0)
        primeiroAluno = ultimoAluno = novoAluno;
    
    else
    {
        for (Aluno *aux = primeiroAluno; aux != NULL; aux = aux->next)
        {
            tamComparacao = 1;
            compNomes = aux->getNome().compare(0, tamComparacao, 
                novoAluno->getNome(), 0, tamComparacao);

            while (compNomes == 0)
                tamComparacao++,
                compNomes = aux->getNome().compare(0, tamComparacao, 
                    novoAluno->getNome(), 0, tamComparacao);

            if (compNomes > 0)
            {
                if (aux->prev) aux->prev->next = novoAluno;
                novoAluno->prev = aux->prev;
                aux->prev = novoAluno;
                novoAluno->next = aux;
                if (aux == primeiroAluno) primeiroAluno = novoAluno;

                countAlunos++;
                return this;
            }
        }

        ultimoAluno->next = novoAluno;
        novoAluno->prev = ultimoAluno;
        ultimoAluno = novoAluno;
    }

    countAlunos++;
    return this;
}

Disciplina *Disciplina::removerAluno(Aluno *aluno)
{
    for (Aluno *aux = primeiroAluno; aux != NULL; aux = aux->next)
    {
        if (aluno == aux)
        {
            if (aux->prev) aux->prev->next = aux->next;
            if (aux->next) aux->next->prev = aux->prev;
            if (aux == primeiroAluno) primeiroAluno = aux->next;
            if (aux == ultimoAluno) ultimoAluno = aux->prev;
            return this;
        }
    }

    std::cout << "Aluno não encontrado\n";
    return this;
} 