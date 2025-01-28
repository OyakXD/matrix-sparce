#include <iostream>
#include <fstream>
#include "SparseMatrix.h"
using namespace std;

void readSparseMatrix(SparseMatrix& m, string arquivo){
  ifstream arquivom(arquivo); // abre e lê o arquivo
  if(!arquivom.is_open()){ // caso não seja possível abrir o arquivo
    cout << "Erro ao ler o arquivo\n" << endl; // saída
    return;
  }

  int linhas; 
  int colunas;
  arquivom >> linhas >> colunas; // pega o número de linha e colunas da matriz;
  
  m.resize(linhas, colunas);

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
  
}