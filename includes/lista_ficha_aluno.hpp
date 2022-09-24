//
// Created by doglasrocha on 9/23/22.
//

#ifndef TEC_PROG_TRABALHOS_LISTA_FICHA_ALUNO_HPP
#define TEC_PROG_TRABALHOS_LISTA_FICHA_ALUNO_HPP

#include "../linked-list/includes/linked-list.hpp"
#include "../linked-list/includes/node.hpp"
#include "ficha_aluno.hpp"

class ListaFichaAluno : public LinkedList<FichaAluno *>
{
    public:
        ListaFichaAluno();
        ~ListaFichaAluno();
        void imprimeAlunos();
        void imprimeFicha();
};


#endif //TEC_PROG_TRABALHOS_LISTA_FICHA_ALUNO_HPP
