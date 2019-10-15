// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// ordenacao.h: Arquivo de declaração de funções para ordenação topológica

#include <vector>
#include <deque>
#include "construction.h"

using namespace std;

// ordenacaoTopologica: Função principal de ordenação topologica
deque<int> ordenacaoTopologica(Grafo& grafo);

// getRoots: Acha todos os vértices que são referenciados por nenhum outro vértice
vector<int> getRoots(Grafo& grafo);

void criaDot(Grafo& grafo, Codigos code, Nomes nome);