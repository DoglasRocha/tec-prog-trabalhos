//
// Created by doglasrocha on 9/23/22.
//

#ifndef TEC_PROG_TRABALHOS_LISTA_ALUNOS_HPP
#define TEC_PROG_TRABALHOS_LISTA_ALUNOS_HPP
#include "../linked-list/includes/linked-list.hpp"
#include "aluno.hpp"

class ListaAlunos : public LinkedList<Aluno *>
{
    public:
        ListaAlunos();
        ~ListaAlunos();

    public:
        void imprimeAlunos();
};

#endif //TEC_PROG_TRABALHOS_LISTA_ALUNOS_HPP
