#pragma once

class Aluno;

class FichaAluno
{
    private:
        Aluno *ptrAluno;
        float notas[2];
        int faltas;

    public:
        FichaAluno(Aluno *ptrAluno_=0);
        ~FichaAluno();
        Aluno *getAluno();
        FichaAluno *setAluno(Aluno *ptrAluno_=0);
        void imprimeNotas();
        float getNota(int numParcial);
        FichaAluno *setNota(float nota, int numParcial);
        int getFaltas();
        FichaAluno *addFaltas(int faltas_);
};
