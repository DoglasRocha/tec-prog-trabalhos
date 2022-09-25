//
// Created by doglasrocha on 9/25/22.
//

#ifndef TEC_PROG_TRABALHOS_LISTA_DEPARTAMENTOS_HPP
#define TEC_PROG_TRABALHOS_LISTA_DEPARTAMENTOS_HPP
#include "../linked-list/includes/linked-list.hpp"
#include "departamento.hpp"

class ListaDepartamentos : public LinkedList<Departamento *>
{
    public:
        ListaDepartamentos();
        ~ListaDepartamentos();
        void imprimeDepartamentos();
        void imprimeDptosEUniv();
};

#endif //TEC_PROG_TRABALHOS_LISTA_DEPARTAMENTOS_HPP
