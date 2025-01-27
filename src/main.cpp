#include <iostream>
#include <fstream>
#include "SparseMatrix.h"
using namespace std;

void readSparseMatrix(SparseMatrix& m, string arquivo){
  ifstream arquivom(arquivo); // abre e lê o arquivo
  if(!arquivom.is_open()){ // caso não seja possível abrir o arquivo
    cout << "Erro ao ler o arquivo"; // saída
    return;
  }

  int linhas; 
  int colunas;
  arquivom >> linhas >> colunas; // pega o número de linha e colunas da matriz;



  int lin, col;
  double valor;
  while(arquivom >> lin >> col >> valor){ // insere os valores na matriz em seus respectivos locais
    m.insert(lin, col, valor);
  }

  arquivom.close(); // fecha o arquivom

}

SparseMatrix sum(SparseMatrix& A, SparseMatrix& B){
  return A + B;
}

SparseMatrix multiply (SparseMatrix& A, SparseMatrix& B){
  return A * B;
}

int main(){
  // Criar uma matriz esparsa vazia com dimensões genéricas
    SparseMatrix matrixA(4, 4); // As dimensões serão ajustadas pela leitura do arquivo.

    // Nome do arquivo que será lido
    string nomeArquivo = "arquivo.txt";

    // Ler a matriz a partir do arquivo
    readSparseMatrix(matrixA, nomeArquivo);

    // Imprimir a matriz carregada
    cout << "Matriz carregada do arquivo:" << endl;
    matrixA.print();

    return 0;
}