#pragma once
#include "universidade.hpp"
#include "professor.hpp"
#include "aluno.hpp"

class Principal
{
    private:
        Professor Simao;
        Aluno Doglas;
        Universidade UTFPR;
        Departamento DAINF;
        Departamento DEDO;
        int diaAtual, mesAtual, anoAtual;
    public:
        Principal();
        ~Principal();
        void executar();
};
