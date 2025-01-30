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
  
  if(linhas <= 0 || colunas <= 0){
    cout << "Dimensões inválidas no arquivo\n";
    return;
  }

  m.resize(linhas, colunas); // dá um resize nas linhas e colunas

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

void opcoes() {
    cout << "\n===== OPÇÕES =====\n";
    cout << "1. Carregar matriz de um arquivo\n";
    cout << "2. Imprimir matriz\n";
    cout << "3. Somar duas matrizes\n";
    cout << "4. Multiplicar duas matrizes\n";
    cout << "5. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    SparseMatrix A, B, C;
    string arquivo;
    int num;

    do{
        opcoes();
        cin >> num;

        switch(num){
          case 1:
            cout << "Digite o nome do arquivo: ";
            cin >> arquivo;
            readSparseMatrix(A, arquivo);
            cout << "Matriz carregada com sucesso.\n";
            break;

          case 2:
            cout << "Matriz atual:\n";
            A.print();
            break;

          case 3:
            cout << "Digite o nome do arquivo para a segunda matriz: ";
            cin >> arquivo;
            readSparseMatrix(B, arquivo);
            C = sum(A, B);
            cout << "Resultado da soma:\n";
            C.print();
            break;

          case 4:
            cout << "Digite o nome do arquivo para a segunda matriz: ";
            cin >> arquivo;
            readSparseMatrix(B, arquivo);
            C = multiply(A, B);
            cout << "Resultado da multiplicação:\n";
            C.print();
            break;

          case 5:
            cout << "Saindo...\n";
            break;

          default:
            cout << "Opção inválida!\n";
        }
    } while(num != 5);
}