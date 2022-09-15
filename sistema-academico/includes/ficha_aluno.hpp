#pragma once

class Aluno;

class FichaAluno
{
    private:
        Aluno *ptrAluno;
        float notas[2];
        int faltas;

    public:
        FichaAluno(Aluno *ptrAluno_=nullptr);
        ~FichaAluno();
        Aluno *getAluno();
        FichaAluno *setAluno(Aluno *ptrAluno_=nullptr);
        void imprimeNotas();
        FichaAluno *setNota(float nota, int numParcial);
        int getFaltas();
        FichaAluno *addFaltas(int faltas_);
};
