#include "ordenacao.h"
#include "grau.h"
#include "dfs.h"
#include <iostream>

// ordenacaoTopologica: Função principal de ordenação topologica
deque<int> ordenacaoTopologica(Grafo& grafo) {
    vector<int> roots;
    vector<bool> vetorBooleano(grafo.size(), true);

    for (auto vert1: grafo) {
        for (auto v : vert1) {
            vetorBooleano[v] = false;
        }
    }
    
    for (unsigned int i = 0; i < vetorBooleano.size(); i++) {
        if (vetorBooleano[i]) {
            roots.push_back(i);
        }
    }

    if (roots.empty()) {
        cout << "Grafo não tem nó sem prerequisitos!!!!\n";
        throw "ERRO: grafo sem raiz";
    }

    // agora percorremos o grafo com DFS em pos ordem, adicionando os vertices em um stack
    deque<int> ord; 
    DFS_inv(grafo, roots, [&ord] (int x) { ord.push_front(x); });
    return ord;
}

void criaDot (Grafo& grafo, Codigos code, Nomes nome) {
    ofstream myfile ("graphviz.dot");
    cout << "alo";
    if (myfile.is_open()) {
        myfile << "graph G {\n";
        for (unsigned int i = 0; i < grafo.size(); i++) {
            for (auto v : grafo[i]) {
              myfile << "       " << nome[i];
              myfile << " -> ";
              myfile << nome[v] << ";" << "\n";
            }
            if (grafo[i].size() == 0) {
                cout << "--";
            }
        } 

        cout << endl;
        } else cout << "Unable to open file";
        myfile << "}";
        myfile.close();
    }

    /*
	for (unsigned int i = 0; i < fluxo.size(); i++) {
		cout << i << ": " << "[" << code[i] << "] " << names[i] << ". Tranca: ";
		if (fluxo[i].size() == 0) {
				cout << "--";
		} else {
			for (auto v : fluxo[i]){
				cout << v << " [" << code[v] << "]" <<"; ";
			}
		} 
		
		cout << endl;
	} */
