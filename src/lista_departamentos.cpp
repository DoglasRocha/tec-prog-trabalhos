//
// Created by doglasrocha on 9/25/22.
//

#include "../includes/lista_departamentos.hpp"
#include "../linked-list/includes/linked-list.hpp"
#include "../includes/departamento.hpp"
#include "../includes/universidade.hpp"
#include <iostream>

ListaDepartamentos::ListaDepartamentos() :
LinkedList<Departamento *>()
{

}

ListaDepartamentos::~ListaDepartamentos() {}

void ListaDepartamentos::imprimeDepartamentos()
{
    for (Node<Departamento *> *aux = head; aux != 0; aux = aux->next)
    {
        std::cout << aux->data->getNome() << std::endl;
    }
}

void ListaDepartamentos::imprimeDptosEUniv()
{
    for (Node<Departamento *> *aux = head; aux != 0; aux = aux->next)
    {
        std::cout << "O " << aux->data->getNome() << " pertence a "
                  << aux->data->getUniversidade()->getNome() << std::endl;
    }
}