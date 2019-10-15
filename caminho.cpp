#include <iostream>
#include "caminho.h"

using namespace std;

#define INF 66666666

// vertice, vertice anterior, distancia entre vertice e origem
typedef pair<int, int> Cam;

// shortestPathToLeaf: encontra o menor caminho para uma folha
// criticalPath: encontra o caminho crítico
deque<int> caminhoCritico(Grafo g, Creditos c, int src) {

    for (unsigned int i = 0; i < c.size(); i++) {
        c[i] *= -1;
    }

    priority_queue<Cam, vector<Cam>, function<bool (Cam, Cam)> >
    caminhos([] (Cam c1, Cam c2) {
        int c1Dist, c2Dist;
        tie (ignore, c1Dist) = c1; // caminhos a serem comparados
        tie (ignore, c2Dist) = c2; // caminhos a serem comparados
        return c1 > c2;
    });

    // vector<vertice de onde veio, distancia até origem>
    vector<pair<int, int> > maisCurto(g.size(), make_pair(src, INF));

    caminhos.push(make_pair(src, 0));
    maisCurto[src] = make_pair(src, 0); 

    vector<bool> folhas(g.size(), false);

    while (!caminhos.empty()) {
        int atual;
        tie (atual, ignore) = caminhos.top();
        // se chegou em um nó folha
        if (g[atual].empty())
            folhas[atual] = true;
        caminhos.pop();

        for (auto v: g[atual]) {
            // se distancia ate atual + peso eh maior que distancia ate v, adicione a queue
            if (maisCurto[v].second > maisCurto[atual].second + c[atual]) {
                // update na distancia
                maisCurto[v] = make_pair(atual, maisCurto[atual].second + c[atual]);
                // coloca o caminho
                caminhos.push(make_pair(v, atual));
            }
        }
    }

    // agora achar a folha com a menor distancia da origem
    int folhaMenor = 0, folhaMenorDist = INF;
    for (unsigned int i = 0; i < g.size(); i++)
        if (folhas[i] && maisCurto[i].second < folhaMenorDist) {
            folhaMenor = i;
            folhaMenorDist = maisCurto[i].second;
        }

    // começar da menor folha, e fazer o caminho reverso até chegar em src
    deque<int> caminhoMenor;
    int noAtual = folhaMenor;
    caminhoMenor.push_front(folhaMenor);
    do {
        caminhoMenor.push_front(maisCurto[noAtual].first);
        noAtual = maisCurto[noAtual].first;
    } while (noAtual != src);

    return caminhoMenor;
}
