#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(){
  this->head = nullptr;
  this->n = 0;
  this->m = 0;
}

SparseMatrix::SparseMatrix(int linhas, int colunas){
  // Inicializa a matriz esparsa
  this->head = nullptr;
  this->m = linhas;
  this->n = colunas;
}

SparseMatrix::~SparseMatrix() {
    Node* atual = head;
    while (atual != nullptr) {
        Node* temp = atual;
        atual = atual->abaixo;
        delete temp; 
    }
    head = nullptr;
}


void SparseMatrix::insert(int i, int j, double value){

  // Validação dos índices
  if (i < 1 || i > this->n || j < 1 || j > this->m){
    throw std::out_of_range("Índices negativos não são permitidos.");
  }

  // Ignorar valores iguais a 0
  if(value == 0){
    return;
  }

  // Inserir ou atualizar o valor na matriz esparsa
  Node* atual = head;
  Node* anterior = nullptr;

  while (atual != nullptr && (atual->linha < i || (atual->linha == i && atual->coluna < j))) {
        anterior = atual;
        atual = atual->abaixo;
  }

  if(atual != nullptr && atual->linha == i && atual->coluna == j){
    // Atualizar o valor existente
    atual->valor = value;
  } else {

    // Insere um novo nó
    Node* novoNo = new Node();
    novoNo->linha = i;
    novoNo->coluna = j;
    novoNo->valor = value;
    novoNo->abaixo = atual;

    if(anterior == nullptr){
      head = novoNo;
    } else {
      anterior->abaixo = novoNo;
    }
  }  
}

// Método que devolve o valor de uma posição da matriz esparsa
double SparseMatrix::get(int i, int j){

   // Validação dos índices
    if(i < 1 || j < 1 || i > this->n || j > this->m){
      throw std::out_of_range("Índices fora do intervalo válido!");
    }


    // Buscar o valor na matriz esparsa
    Node* atual = head;

    // Percorrer a matriz esparsa
    while (atual != nullptr) {
        // Se encontrar o nó com os índices (i, j), retornar o valor
        if (atual->linha == i && atual->coluna == j) {
            return atual->valor;
        }
        // Se passar da linha ou coluna desejada, pode parar (lista ordenada)
        if (atual->linha > i || (atual->linha == i && atual->coluna > j)) {
            break;
        }
        atual = atual->abaixo;
    }

    // Se o valor não foi encontrado, retornar 0
    return 0;
  }

  // Método que imprime a matriz esparsa
  void SparseMatrix::print(){

    // Imprimir todos os elementos, inclusive zeros
    for(int i = 1; i <= this->m; i++){
      for(int j = 1; j <= this->n; j++){
        std::cout << get(i, j) << " ";
      }
      std::cout << std::endl;
    }
  }

  void SparseMatrix::resize(int linhas, int colunas){
    Node* atual = head;
    while (atual != nullptr) {
      Node* temp = atual;
      atual = atual->abaixo;
      delete temp;
    }

    this->head = nullptr;
    this->m = linhas;
    this->n = colunas;
  }

  SparseMatrix SparseMatrix::operator+(SparseMatrix& matrix) {

    if(this->m != matrix.m || this->n != matrix.n){
      throw std::out_of_range("Não foi possivel somar");
    }

    SparseMatrix result(this->m, this->n);
    
    for(int i = 1; i <= this->m; i++){
      for(int j = 1; j <= this->n; j++){
        result.insert(i, j, this->get(i, j) + matrix.get(i, j));
      }
    }

    return result;

  }

  SparseMatrix SparseMatrix::operator*(SparseMatrix& matrix) {
    if(this->n != matrix.m){
      throw std::out_of_range("Não é possivel multiplicar");
    }

     SparseMatrix result(this->m, matrix.n);

     // Declara uma variável auxiliar a para armazenar o valor acumulado de cada elemento
     // da matriz resultado
     double a;

    for(int i = 1; i <= this->m; i++){ 
      for(int j = 1; j <= matrix.n; j++){ 
        a = 0.0; 

        // Calculo do elemento resultante
        for(int k = 1; k <= this->n; k++){ // Itera sobre os indices intermediários para calcular o produto escalar
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
 
