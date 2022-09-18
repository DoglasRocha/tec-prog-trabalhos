#pragma once
#include "universidade.hpp"
#include "professor.hpp"
#include "aluno.hpp"
#include "disciplina.hpp"
#include "departamento.hpp"
#include "../linked-list/includes/linked-list.hpp"
#include "../linked-list/src/linked-list.cpp"

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
        LinkedList<Professor *> ListaProfessores;
        LinkedList<Aluno *> ListaAlunos;
        LinkedList<Universidade *> ListaUniversidades;
        LinkedList<Departamento *> ListaDepartamentos;
        LinkedList<Disciplina *> ListaDisciplinas;

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
        void cadastraAluno();
        void cadastraProfessor();
        void cadastraDisciplina();
        void cadastraDepartamento();
        void cadastraUniversidade();
};
