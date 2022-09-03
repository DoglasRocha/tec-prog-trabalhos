#pragma once
#include <string>

class Universidade;

class Departamento
{
    private:
        std::string nome;
        Universidade *univ;

    public:
        Departamento(std::string nome_="");
        ~Departamento();
        std::string getNome();
        Departamento *setNome(std::string nome_="");
        Universidade *getUniversidade();
        Departamento *setUniversidade(Universidade *universidade);
};
