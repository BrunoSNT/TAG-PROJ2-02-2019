#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <iostream>
#include "construction.h"

using namespace std;

// createGrafo: A partir do nome do arquivo, chama as funções para criação do grafo.
vector<vector<int> > criarGrafo (const string& fileName) {
    fstream arquivo(fileName);

    int tamanho = grafoSize(arquivo); 

    Grafo g;
    
    for (size_t i = 0; i < tamanho; i++) {
		g.push_back(vector<int>());
	}

    makeEdges(arquivo, g);
    return g;
}

// grafoSize: A partir do arquivo, procura onde "node" é citado para retornar número de vértices. 
size_t grafoSize (fstream& fileStream) {

	string buffer;
	size_t size = 0;

	if (fileStream.is_open()) {
		while (getline (fileStream, buffer)) {
			if (buffer.find("node") != string::npos)
				size++;
			else if (buffer.find("aresta") != string::npos)
				break;
		}
	}
	else {
		throw "Erro ao ler o arquivo!";
	}
	return size;
}

// makeEdges: utilizando o arquivo e a função connectEdge, essa função lê o arquivo e identifica
// as palavras 'source' e 'edge' para definir os vizinhos de cada vértice.
void makeEdges (fstream& fileStream, vector<vector<int> >& grafo) {

	if (!fileStream.is_open())
		throw "Erro ao ler o arquivo";

	string buffer;
	while (getline(fileStream, buffer)) {
		if (buffer.find("source") != string::npos) {
			int v1,v2 = 0;

            sscanf(buffer.c_str(), "    source %d", &v1);
            getline(fileStream, buffer);
            sscanf(buffer.c_str(), "    target %d", &v2);

			if ((unsigned int) (v1-1) >= grafo.size() || (unsigned int) (v2-1) >= grafo.size())
				throw "Este vertice nao existe"; //caso o vértice não exista
			grafo[v1-1].push_back(v2-1);
		}
	}
}


// setupNames: através do arquivo, cria e retorna um vetor constando todos os nomes lidos no arquivo 
vector<string> vetorizaNomes (fstream& fileStream) {
	if (!fileStream.is_open()){
		printf("Erro na leitura do arquivo");
		exit(EXIT_FAILURE);
	}
	Nomes  n;
	string buffer;
	while (getline(fileStream, buffer)) {
		if (buffer.find("nome") != string::npos) {			//Procura a palavra chave no código
			char name[64];
			string name_str;

			sscanf(buffer.c_str(), "    nome %s", name);	//Captura o valor desejado na linha

			name_str.insert(0, name); 										

			n.push_back(name_str);												//Insere no vetor
		}

		if (buffer.find("aresta") != string::npos) {
      		
			  return n;
    }
	}
	return n;
}

// setupCredits: através do arquivo, cria e retorna um vetor constando todos os créditos lidos no arquivo 
vector<int> vetorizaCreditos (fstream& fileStream) {
	if (!fileStream.is_open()){
		throw "Erro ao ler o arquivo";
	}

	string buffer;
	Creditos c;
	while (getline(fileStream, buffer)) {
		if (buffer.find("creditos") != string::npos) {					//Procura a palavra chave no código
			int credit = 0;

			sscanf(buffer.c_str(), "    creditos %d", &credit);		//Captura o valor desejado na linha

			c.push_back(credit);																	//Insere no vetor
		}

		if (buffer.find("aresta") != string::npos) {
      		
			  return c;
    	}
	}

	return c;
}

// setupStress: através do arquivo, cria e retorna um vetor constando todos as dificuldades lidas no arquivo 
vector<float> vetorizaCodigos (fstream& fileStream){
	if (!fileStream.is_open()){
		throw "Erro ao ler o arquivo";
	}

	string buffer;
	Codigos s;
	while (getline(fileStream, buffer)) {
		if (buffer.find("codigo") != string::npos) { 					//Procura a palavra chave no código
			float code = 0;

			sscanf(buffer.c_str(), "    codigo %f", &code);	//Captura o valor desejado na linha

			s.push_back(code);																		//Insere no vetor
		}

		if (buffer.find("aresta") != string::npos) {
      		
			  return s;
    	}
	}

	return s;
}