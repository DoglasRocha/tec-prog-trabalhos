//
// Created by doglasrocha on 9/23/22.
//

#include "../includes/lista_ficha_aluno.hpp"
#include "../includes/ficha_aluno.hpp"
#include "../includes/aluno.hpp"

ListaFichaAluno::ListaFichaAluno() :
LinkedList<FichaAluno *>()
{

}

ListaFichaAluno::~ListaFichaAluno()
{

}

void ListaFichaAluno::imprimeAlunos()
{
    for (Node<FichaAluno *> *aux = head; aux != 0; aux = aux->next)
    {
        std::cout << aux->data->getAluno()->getNome() << std::endl;
    }
}

void ListaFichaAluno::imprimeFicha()
{
    for (Node<FichaAluno *> *aux = head; aux!= 0; aux = aux->next)
    {
        std::cout << aux->data->getAluno()->getNome() << ", " << std::endl
                  << "\tnota 1ª parcial:" << aux->data->getNota(0) << std::endl
                  << "\tnota 2ª parcial:" << aux->data->getNota(1) << std::endl
                  << "\tfaltas: " << aux->data->getFaltas() << std::endl;
    }
}
