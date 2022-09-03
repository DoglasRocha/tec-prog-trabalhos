#include <iostream>
#include "../includes/principal.hpp"
#include "../includes/pessoa.hpp"
#include "../includes/universidade.hpp"
#include "../includes/aluno.hpp"

Principal::Principal()
{
    std::cout << "Digite dia, mês e ano atual, separados por espaços: ";
    std::cin >> diaAtual >> mesAtual >> anoAtual;
    
    inicializa();
    executar();
}

Principal::~Principal() {}

void Principal::inicializa()
{
    inicializaPessoas();
    inicializaUniversidades();
    inicializaDepartamentos();
    inicializaDisciplinas();
}

void Principal::inicializaPessoas()
{
    Simao.setDataNasc(30, 8, 1971)->setNome("Simão");
    Simao.setUniversidade(&UTFPR)->setDepartamento(&DAINF);

    Doglas.setDataNasc(11, 1, 2003)->setNome("Doglas");
    Doglas.setRA(2450054)->setUnivAssociado(&UTFPR)->setDptoAssociado(&DAINF);
}

void Principal::inicializaUniversidades()
{
    UTFPR.setNome("Universidade Tecnológica Federal do Paraná");
    UTFPR.setDepartamento(&DAINF)->setDepartamento(&DEDO);
}

void Principal::inicializaDepartamentos()
{
    DAINF.setNome("Departamento Acadêmico de Informática");
    DEDO.setNome("Departamento Exterior Digital Obrigatório");
}

void Principal::inicializaDisciplinas()
{
    Prolegomenos.setNome("Prolegômenos ao Computar")->setAreaConhecimento("Introdução a Computação");
    TecProg.setNome("Técnicas de Programação")->setAreaConhecimento("Programação Orientada a Objetos");

    Prolegomenos.setDptoAssociado(&DAINF);
    TecProg.setDptoAssociado(&DAINF);
}


void Principal::executar()
{
    Doglas.calculaIdade(diaAtual, mesAtual, anoAtual);
    Doglas.informaIdade();
    
    Simao.ondeTrabalha();
    Doglas.ondeEstuda();
    UTFPR.imprimeDepartamentos();
    DAINF.imprimeDisciplinas();
}