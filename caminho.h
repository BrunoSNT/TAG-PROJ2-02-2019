// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// caminho.h: Arquivo de declaração de funções para buscar caminho crítico

#include <vector>
#include <deque>
#include <queue>
#include <functional>
#include "construction.h"

using namespace std;

typedef pair<int, vector<int> > Caminho;

// criticalPath: encontra o caminho crítico
deque<int> caminhoCritico(Grafo g, Creditos c, int src);