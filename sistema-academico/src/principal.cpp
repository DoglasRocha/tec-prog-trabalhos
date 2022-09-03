#include <iostream>
#include "../includes/principal.hpp"
#include "../includes/pessoa.hpp"
#include "../includes/universidade.hpp"
#include "../includes/aluno.hpp"

Principal::Principal()
{
    Simao.setDataNasc(30, 8, 1971)->setNome("Simão");
    Doglas.setDataNasc(11, 1, 2003)->setNome("Doglas");
    Doglas.setRA(2450054);
    UTFPR.setNome("Universidade Tecnológica Federal do Paraná");
    DAINF.setNome("Departamento Acadêmico de Informática");
    DEDO.setNome("Departamento Exterior Digital Obrigatório");

    std::cout << "Digite dia, mês e ano atual, separados por espaços: ";
    std::cin >> diaAtual >> mesAtual >> anoAtual;

    Simao.setUniversidade(&UTFPR)->setDepartamento(&DAINF);
    UTFPR.setDepartamento(&DAINF)->setDepartamento(&DEDO);
    executar();
}

Principal::~Principal() {}

void Principal::executar()
{
    Doglas.calculaIdade(diaAtual, mesAtual, anoAtual);
    Doglas.informaIdade();
    
    Simao.ondeTrabalha();
    UTFPR.imprimeDepartamentos();
}