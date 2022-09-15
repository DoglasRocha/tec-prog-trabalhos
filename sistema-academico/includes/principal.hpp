#pragma once
#include "universidade.hpp"
#include "professor.hpp"
#include "aluno.hpp"
#include "disciplina.hpp"
#include "departamento.hpp"

class Principal
{
    private:
        Professor *Simao;
        Aluno *Doglas, *abrao, *altair, *zulmir;
        Universidade *UTFPR;
        Departamento *DAINF;
        Departamento *DEDO;
        Disciplina *Prolegomenos;
        Disciplina *TecProg;
        
        // int diaAtual, mesAtual, anoAtual;
        
    public:
        Principal();
        ~Principal();
        void inicializa();
        void inicializaPessoas();
        void inicializaUniversidades();
        void inicializaDepartamentos();
        void inicializaDisciplinas();
        void bind();
        void bindPessoas();
        void bindUniversidades();
        void bindDepartamentos();
        void bindDisciplinas();
        void executar();
        void menu();
        void menuCadastro();
        void menuExecucao();
};
