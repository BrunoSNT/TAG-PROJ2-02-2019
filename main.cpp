#include <iostream>
#include <vector>
#include <list>
#include "construction.h"
#include "ordenacao.h"
#include "caminho.h"
#include "dfs.h"

using namespace std;

void a(int v) {
	cout << v << " ";
}

int main(int argc, char** argv) {


	Nomes names;
	Creditos credits;
	Codigos code;
	fstream arquivo1("grafo.txt");
	fstream arquivo2("grafo.txt");
	fstream arquivo3("grafo.txt");

	Grafo fluxo = criarGrafo ("grafo.txt");
	names = vetorizaNomes(arquivo1);
	credits = vetorizaCreditos(arquivo2);
	code = vetorizaCodigos(arquivo3);

	deque<int> ordenado = ordenacaoTopologica(fluxo);
	deque<int> caminho  = caminhoCritico(fluxo, credits, 0);
	criaDot(fluxo, code, names);

	cout << endl << "Fluxo de matérias: " << endl << endl;
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
	}
	
	cout << endl << "Ordenação topológica: " << endl;
	int j = 0;
	for (auto v : ordenado) {
		j++;
		cout << j << ": " << v << " - " << names[v] << endl;
	}
	j = 0;
	cout << endl << "Caminho crítico: " << endl;
	for (auto v : caminho) {
		j++;
		cout << j << ": " << v << " - " << names[v] << endl;
	}

	return 0;

}