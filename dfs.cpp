#include "dfs.h"

// DFS_post: Percorre o grafo em DFS, e executa foo() com cada vertice v em pos-ordem
void DFS_inv(Grafo& grafo, vector<int> raizes, function<void (int)> foo) {

    vector<bool> checados(grafo.size(), false); 
    
    // iterar o DFS em todos os vértices dados, se não tiverem sido visitados
    if (raizes.size() > 0)
    for (auto no: raizes)
        if (!checados[no]) DFS_aux(grafo, no, checados, foo);

    // fazer os outros caminhos, se existirem
    for (unsigned int i = 0; i < checados.size(); i++)
        if (!checados[i]) DFS_aux(grafo, i, checados, foo);
}

// DFS_post_util: Função recursiva auxiliar de DFS_post
void DFS_aux(Grafo& grafo, int atual, vector<bool>& checados, function<void (int)> foo) {
    checados[atual] = true;
    for (auto no : grafo[atual])
        if (!checados[no]) {
            DFS_aux(grafo, no, checados, foo);
        }
    foo(atual);
}