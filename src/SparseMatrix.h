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
  SparseMatrix() = default;

  // Destructor padrão
  ~SparseMatrix();
  
  // Método que insere um valor na matriz esparsa
  void insert(int i, int j, double value);

  double get(int i, int j);

  void print();

};

#endif
