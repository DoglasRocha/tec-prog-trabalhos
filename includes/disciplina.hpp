#pragma once
#include <string>
#include "lista_ficha_aluno.hpp"
#include "../includes/ficha_aluno.hpp"

class Departamento;
class Aluno;

class Disciplina
{
    private:
        std::string nome;
        std::string areaConhecimento;
        Departamento *dptoAssociado;
        int numeroMaxAlunos;

    public:
        ListaFichaAluno listaAlunos;
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
        Disciplina *removerAluno(Aluno *aluno);
};