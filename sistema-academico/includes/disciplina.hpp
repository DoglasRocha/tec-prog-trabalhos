#pragma once
#include <string>

class Departamento;

class Disciplina
{
    private:
        std::string nome;
        std::string areaConhecimento;
        Departamento *dptoAssociado;

    public:
        Disciplina *next;

        Disciplina(std::string nome_="", std::string areaConhecimento_="");
        ~Disciplina();

        std::string getNome();
        Disciplina *setNome(std::string nome_="");
        std::string getAreaConhecimento();
        Disciplina *setAreaConhecimento(std::string areaConhecimento_="");
        Departamento *getDptoAssociado();
        Disciplina *setDptoAssociado(Departamento *departamento);
};