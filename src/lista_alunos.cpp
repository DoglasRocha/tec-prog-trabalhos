//
// Created by doglasrocha on 9/23/22.
//
#include "../includes/lista_alunos.hpp"
#include "../linked-list/includes/linked-list.hpp"
#include "../linked-list/includes/node.hpp"

ListaAlunos::ListaAlunos() :
LinkedList<Aluno *>()
{
}

ListaAlunos::~ListaAlunos()
{
}

void ListaAlunos::imprimeAlunos()
{
    for (Node<Aluno *> *aux = head; aux != 0; aux = aux->next)
    {
        std::cout << aux->data->getNome() << std::endl;
    }
}
