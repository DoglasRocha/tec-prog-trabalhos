#include <iostream>
#include "../includes/principal.hpp"
#include "../includes/pessoa.hpp"
#include "../includes/universidade.hpp"
#include "../includes/aluno.hpp"

Principal::Principal()
{
    //std::cout << "Digite dia, mês e ano atual, separados por espaços: ";
    //std::cin >> diaAtual >> mesAtual >> anoAtual;
    inicializa();
    bind();
    executar();
}

Principal::~Principal() {
    delete Simao;
    delete Doglas;
    delete abrao;
    delete altair;
    delete zulmir;
    delete UTFPR;
    delete DAINF;
    delete DEDO;
    delete Prolegomenos;
    delete TecProg;
}

void Principal::inicializa()
{
    inicializaPessoas();
    inicializaUniversidades();
    inicializaDepartamentos();
    inicializaDisciplinas();
}

void Principal::inicializaPessoas()
{
    Simao = new Professor(30, 8, 1971, "Jean Simão");
    Doglas = new Aluno(11, 1, 2003, "Doglas", 2450054);
    abrao = new Aluno(12, 5, 2003, "Abrão da Silva Pinto", 2450055);
    altair = new Aluno(13, 6, 2003, "Altair Carneiro de Santos", 2450056);
    zulmir = new Aluno(14, 7, 2003, "Zulmir Gouveia de Almeida", 2450056);
}

void Principal::inicializaUniversidades()
{
    UTFPR = new Universidade("Universidade Tecnológica Federal do Paraná");
}

void Principal::inicializaDepartamentos()
{
    DAINF = new Departamento("Departamento Acadêmico de Informática");
    DEDO = new Departamento("Departamento Exterior Digital Obrigatório");
}

void Principal::inicializaDisciplinas()
{
    Prolegomenos = new Disciplina("Prolegômenos ao Computar", "Introdução a Computação");
    TecProg = new Disciplina("Técnicas de Programação", "Programação Orientada a Objetos");
}

void Principal::bind()
{
    bindPessoas();
    bindUniversidades();
    bindDepartamentos();
    bindDisciplinas();
}

void Principal::bindPessoas()
{
    Simao->setUniversidade(UTFPR)->setDepartamento(DAINF);
    Doglas->setUnivAssociado(UTFPR)->setDptoAssociado(DAINF);
    abrao->setUnivAssociado(UTFPR)->setDptoAssociado(DAINF);
    altair->setUnivAssociado(UTFPR)->setDptoAssociado(DAINF);
    zulmir->setUnivAssociado(UTFPR)->setDptoAssociado(DAINF);
}

void Principal::bindUniversidades()
{
    UTFPR->setDepartamento(DAINF)->setDepartamento(DEDO);
}

void Principal::bindDepartamentos()
{

}

void Principal::bindDisciplinas()
{
    Prolegomenos->setDptoAssociado(DAINF);
    TecProg->setDptoAssociado(DAINF);

    Prolegomenos->
        addAluno(Doglas)->
        addAluno(altair)->
        addAluno(zulmir)->
        addAluno(abrao);
}

void Principal::executar()
{
    Simao->ondeTrabalha();
    Doglas->ondeEstuda();
    UTFPR->imprimeDepartamentos(); 
    DAINF->imprimeDisciplinas();
    Prolegomenos->imprimeAlunos();
}