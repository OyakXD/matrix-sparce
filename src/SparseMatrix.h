#ifndef MATRIX_H
#define MATRIX_H
#include "Node.h"

/*
  Classe que representa uma matriz esparsa.
  aqui temos alguns métodos (TAD) que manipulam uma matriz esparsa.
 */
class SparseMatrix{
  
  // Node é uma struct que representa um nó da matriz esparsa.
  private:
  int n;
  int m;

  public:

  Node *head;
  
  // Construtor padrão
  SparseMatrix();

  // Construtor com parâmetros
  SparseMatrix(int linhas, int colunas);

  // Destructor padrão
  ~SparseMatrix();
  
  // Método que insere um valor na matriz esparsa
  void insert(int i, int j, double value);

  // Método que vai pegar elemento dada posição (I,J);
  double get(int i, int j);

  // Método que mostra a matriz esparsa
  void print();

  // Sobrecarga de operador de multiplicação
  SparseMatrix operator*(SparseMatrix& matrix);

  // Sobrecarga do operador de soma
  SparseMatrix operator+(SparseMatrix& matrix);

};
#endif
