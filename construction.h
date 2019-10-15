// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// construction.h: Declaração de funções necessárias para a montagem do grafo e seus vetores auxiliares

#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<int> > Grafo;
typedef vector<string> Nomes;
typedef vector<int> Creditos;
typedef vector<float> Codigos;

// createGrafo: A partir do nome do arquivo, chama as funções para criação do grafo.
vector<vector<int> > criarGrafo (const string& fileName);

// makeEdges: utilizando o arquivo e a função connectEdge, essa função lê o arquivo e identifica
// as palavras 'source' e 'edge' para definir os vizinhos de cada vértice.
void makeEdges (fstream& fileStream, vector<vector<int> >& grafo);

// grafoSize: A partir do arquivo, procura onde "node" é citado para retornar número de vértices. 
size_t grafoSize (fstream& fileStream);

// monta os vetores com informações sobre as matérias
// setupNames: através do arquivo, cria e retorna um vetor constando todos os nomes lidos no arquivo 
vector<string> vetorizaNomes (fstream& fileStream);

// setupCredits: através do arquivo, cria e retorna um vetor constando todos os créditos lidos no arquivo 
vector<int> vetorizaCreditos (fstream& fileStream);

// setupStress: através do arquivo, cria e retorna um vetor constando todos as dificuldades lidas no arquivo 
vector<float> vetorizaCodigos (fstream& fileStream);