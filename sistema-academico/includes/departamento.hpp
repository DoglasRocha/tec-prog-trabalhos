#pragma once
#include <string>

class Departamento
{
    private:
        std::string nome;

    public:
        Departamento(std::string nome_="");
        ~Departamento();
        std::string getNome();
        void setNome(std::string nome_="");
};
