#pragma once
#include <string>

class Disciplina;
class Universidade;

class Departamento
{
    private:
        std::string nome;
        Universidade *univ;
        Disciplina *primeiraDisciplina;
        Disciplina *ultimaDisciplina;

    public:
        Departamento(std::string nome_="");
        ~Departamento();
        std::string getNome();
        Departamento *setNome(std::string nome_="");
        Universidade *getUniversidade();
        Departamento *setUniversidade(Universidade *universidade);
        Departamento *addDisciplina(Disciplina *disciplina);
        void imprimeDisciplinas();
};
