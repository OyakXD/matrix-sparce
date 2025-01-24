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
  SparseMatrix(int linhas, int colunas){
    // Inicializa a matriz esparsa
    head = nullptr;
    n = linhas;
    m = colunas;
  }

  // Destructor padrão
  ~SparseMatrix();
  
  // Método que insere um valor na matriz esparsa
  void insert(int i, int j, double value);

  double get(int i, int j);

  void print();

  // Sobrecarga de operador de multiplicação
  SparseMatrix& operator*(SparseMatrix& matrix){

    // Condicional: Verifica se o número de colunas da matriz atual é diferente do número de linhas da matriz m.
    // Essa condição é essencial porque, em multiplicação de matrizes o número de colunas da matriz 
    // à esquerda deve ser igual ao número de linhas da matriz à direita.
    if(this->n != matrix.m){
      throw std::out_of_range("Não é possivel multiplicar");
    }

     SparseMatrix result(m, matrix.n);

     // Declara uma variável auxiliar a para armazenar o valor acumulado de cada elemento
     // da matriz resultado
     double a;

    for(int i = 0; i < this->m; i++){ 
      for(int j = 0; j < matrix.n; j++){ 
        a = 0.0; 

        // Calculo do elemento resultante
        for(int k = 0; k < this->n; k++){ // Itera sobre os indices intermediários para calcular o produto escalar
          a += this->get(i, k) * matrix.get(k, j);
        }
          
        if(a != 0.0){
          result.insert(i, j, a);
        }
      }
    }

    // Retorno
    return result;
  }

  // Sobrecarga do operador de soma
  SparseMatrix& operator+(SparseMatrix& matrix){

    if(this->m != matrix.m || this->n != matrix.n){
      throw std::out_of_range("Não foi possivel somar");
    }

    SparseMatrix result(this->m, this->n);
    
    for(int i = 0; i < this->m; i++){
      for(int j = 0; j < this->n; j++){
        result.insert(i, j, this->get(i, j) + matrix.get(i, j));
      }
    }

    return result;
  }

};

#endif
