#include <iostream>
#include "../includes/principal.hpp"
#include "../includes/pessoa.hpp"
#include "../includes/universidade.hpp"

Principal::Principal()
{
    Doglas = Pessoa(11, 1, 2003, "Doglas");
    UTFPR.setNome("Universidade Tecnológica Federal do Paraná");

    std::cout << "Digite dia, mês e ano atual, separados por espaços: ";
    std::cin >> diaAtual >> mesAtual >> anoAtual;

    Doglas.setUniversidade(&UTFPR);
    executar();
}

Principal::~Principal() {}

void Principal::executar()
{
    Doglas.calculaIdade(diaAtual, mesAtual, anoAtual);
    Doglas.informaIdade();
    
    Doglas.ondeTrabalha();
}