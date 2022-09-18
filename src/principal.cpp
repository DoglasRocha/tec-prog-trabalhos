#include <iostream>
#include "../includes/principal.hpp"
using std::cout;
using std::cin;
using std::endl;

Principal::Principal()
{
    //std::cout << "Digite dia, mês e ano atual, separados por espaços: ";
    //std::cin >> diaAtual >> mesAtual >> anoAtual;
    Simao = 0;
    Doglas = 0;
    abrao = 0;
    altair = 0;
    zulmir = 0;
    UTFPR = 0;
    DAINF = 0;
    DEDO = 0;
    Prolegomenos = 0;
    TecProg = 0;
    inicializa();
    bind();
    executar();
}

Principal::~Principal() {
    for (int i = 0, l = ListaDisciplinas.getLength(); i < l; i++)
        delete ListaDisciplinas[i];

    for (int i = 0, l = ListaUniversidades.getLength(); i < l; i++)
        delete ListaUniversidades[i];

    for (int i = 0, l = ListaAlunos.getLength(); i < l; i++)
        delete ListaAlunos[i];

    for (int i = 0, l = ListaDepartamentos.getLength(); i < l; i++)
        delete ListaDepartamentos[i];

    for (int i = 0, l = ListaProfessores.getLength(); i < l; i++)
        delete ListaProfessores[i];
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
    ListaProfessores.append(Simao);

    Doglas = new Aluno(11, 1, 2003, "Doglas", 2450054);
    abrao = new Aluno(12, 5, 2003, "Abrão da Silva Pinto", 2450055);
    altair = new Aluno(13, 6, 2003, "Altair Carneiro de Santos", 2450056);
    zulmir = new Aluno(14, 7, 2003, "Zulmir Gouveia de Almeida", 2450056);
    ListaAlunos.
        append(Doglas)->
        append(abrao)->
        append(altair)->
        append(zulmir);
}

void Principal::inicializaUniversidades()
{
    UTFPR = new Universidade("Universidade Tecnológica Federal do Paraná");
    ListaUniversidades.append(UTFPR);
}

void Principal::inicializaDepartamentos()
{
    DAINF = new Departamento("Departamento Acadêmico de Informática");
    DEDO = new Departamento("Departamento Exterior Digital Obrigatório");
    ListaDepartamentos.append(DAINF)->append(DEDO);
}

void Principal::inicializaDisciplinas()
{
    Prolegomenos = new Disciplina("Prolegômenos ao Computar", "Introdução a Computação");
    TecProg = new Disciplina("Técnicas de Programação", "Programação Orientada a Objetos");
    ListaDisciplinas.append(Prolegomenos)->append(TecProg);
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

void Principal::menu()
{
    int opcao;

    cout << "O que você deseja fazer?" << endl
         << "(1) Cadastrar" << endl
         << "(2) Listar" << endl
         << "(3) Sair" << endl;

    cin >>  opcao;

    switch (opcao) {
        case 1:
            menuCadastro();
            break;

        case 2:
            menuExecucao();
            break;

        case 3:
            break;

        default:
            cout << "Opção inválida!!" << endl;
            menu();
    }
}

void Principal::menuCadastro()
{
    int opcao;

    cout << "O que você deseja cadastrar? " << endl
         << "(1) Aluno" << endl
         << "(2) Professor" << endl
         << "(3) Disciplina" << endl
         << "(4) Departamento" << endl
         << "(5) Universidade" << endl
         << "(6) Voltar" << endl;

    switch (opcao)
    {
        case 1:
            cadastraAluno();
            break;

        case 2:
            cadastraProfessor();
            break;

        case 3:
            cadastraDisciplina();
            break;

        case 4:
            cadastraDepartamento();
            break;

        case 5:
            cadastraUniversidade();
            break;

        case 6:
            menu();
            break;

        default:
            cout << "Opção inválida!!" << endl;
            menuCadastro();
    }
}

void Principal::menuExecucao()
{

}

void Principal::cadastraAluno()
{
    std::string nome, departamento, universidade;
    int dia, mes, ano, RA, qtdDisciplinas, flag = 0;
    Aluno *novoAluno;

    cout << "Digite o nome do Aluno: ";
    cin >> nome;

    cout << "Digite o dia, mês e ano de nascimento do aluno, separados por espaços: ";
    cin >> dia >> mes >> ano;

    cout << "Digite o Registro Acadêmico do aluno: ";
    cin >> RA;

    novoAluno = new Aluno(dia, mes, ano, nome, RA);
    ListaAlunos.append(novoAluno);

    do
    {
        cout << "Em qual universidade esse aluno está matriculado? ";
        cin >> universidade;

        for (int i = 0, l = ListaUniversidades.getLength(); i < l; ++i)
            if (ListaUniversidades[i]->getNome() == universidade)
            {
                flag = 1;
                novoAluno->setUnivAssociado(ListaUniversidades[i]);
                break;
            }

        if (!flag)
            cout << "Universidade não encontrada!!" << endl;

    }
    while (!flag);

    flag = 0;
    do
    {
        cout << "Em qual departamento este aluno está associado? ";
        cin >> departamento;
        LinkedList<Departamento *> listaDptos = novoAluno->getUnivAssociado()->getDptos();

        for (int i = 0, l = listaDptos.getLength(); i < l; i++)
        {
            if (listaDptos[i]->getNome() == departamento)
            {
                flag = 1;
                novoAluno->setDptoAssociado(listaDptos[i]);
                break;
            }

            if (!flag)
                cout << "Departamento não encontrado!!" << endl;
        }
    }
    while (!flag);

    flag = 0;
}

void Principal::cadastraProfessor()
{

}

void Principal::cadastraDisciplina()
{

}

void Principal::cadastraDepartamento()
{

}

void Principal::cadastraUniversidade()
{

}
