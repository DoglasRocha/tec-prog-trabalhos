#pragma once
#include <string>

class Departamento;
class Aluno;

class Disciplina
{
    private:
        std::string nome;
        std::string areaConhecimento;
        Departamento *dptoAssociado;
        Aluno *primeiroAluno;
        Aluno *ultimoAluno;
        int numeroMaxAlunos, countAlunos;

    public:
        Disciplina *next, *prev;

        Disciplina(std::string nome_="", std::string areaConhecimento_="");
        ~Disciplina();

        std::string getNome();
        Disciplina *setNome(std::string nome_="");
        std::string getAreaConhecimento();
        Disciplina *setAreaConhecimento(std::string areaConhecimento_="");
        Departamento *getDptoAssociado();
        Disciplina *setDptoAssociado(Departamento *departamento);
        void imprimeAlunos();
        Disciplina *addAluno(Aluno *novoAluno);
};