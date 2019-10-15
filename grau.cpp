// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// grau.cpp: Arquivo da implementação das funções relacionadas ao grau dos vértices


#include "grau.h"
#include <iostream>

using namespace std;

// getGrauNode: dado um vértice, é retornado o tamanho do vetor da lista de adjacências desse
// vértice. Logo, é o grau do vértice
int getGrauNode(Node& vertice) {
    return vertice.size();
}

// displayGrauNode: imprime na tela o índice do vértice e o seu respectivo grau.
void displayGrauNode(int indice, Node& vertice) {
    cout << "Vértice " << indice+1 << ": Grau " << getGrauNode(vertice) << endl;
}