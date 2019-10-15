#include <vector>
#include <functional>
#include "construction.h"

using namespace std;

// DFS_post: Percorre o grafo em DFS, e executa foo() com cada vertice v em pos-ordem
void DFS_inv(Grafo& grafo, vector<int> raizes, function<void (int)> foo);

// DFS_post_util: Função recursiva auxiliar de DFS_post
void DFS_aux(Grafo& grafo, int atual, vector<bool>& checado, function<void (int)> foo);