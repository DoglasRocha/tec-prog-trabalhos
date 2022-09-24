cmake_minimum_required(VERSION 3.23)
project(tec_prog_trabalhos)

set(CMAKE_CXX_STANDARD 98)
include_directories(${PROJECT_SOURCE_DIR}/includes)
file(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB LINKED-LIST-SRC "${PROJECT_SOURCE_DIR}/linked-list/src/*.cpp")

add_executable(tec_prog_trabalhos main.cpp ${SRC} ${LINKED-LIST-SRC} includes/cadastro.hpp src/cadastro.cpp includes/lista_alunos.hpp src/lista_alunos.cpp src/lista_ficha_aluno.cpp includes/lista_ficha_aluno.hpp)
