#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(){
  // Inicializa a matriz esparsa
  head = nullptr;
}

void SparseMatrix::insert(int i, int j, double value){

  // Validação dos índices
  if(i < 0 || j < 0){
    throw std::out_of_range("Índices negativos não são permitidos.");
  }

  // Ignorar valores iguais a 0
  if(value == 0){
    return;
  }

  // Inserir ou atualizar o valor na matriz esparsa
  Node* atual = head;
  Node* anterior = nullptr;

  while(atual != nullptr && (atual->linha < i || (atual->linha == i && atual->coluna < j))){
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
    if (i < 0 || j < 0) {
        throw std::out_of_range("Índices fora do intervalo válido!");
    }

    // Buscar o valor na matriz esparsa
    Node* atual = head;

    // Percorrer a matriz esparsa
    while(atual != nullptr && (atual->linha < i || (atual->linha == i && atual->coluna < j))){
      // Atualizar o nó atual
      atual = atual->abaixo;
    }

    // Verificar se o valor foi encontrado
    if(atual != nullptr && atual->linha == i && atual->coluna == j){
      return atual->valor;
    } else {
      return 0;
    }  
  }

  // Método que imprime a matriz esparsa
  void SparseMatrix::print(){

    // Determinar o maior índice de linha e coluna presentes
    int maxRow = 0, maxCol = 0;

    // Percorrer a matriz esparsa
    Node* aux = head;
    while(aux != nullptr){
      if(aux->linha > maxRow) maxRow = aux->linha;
      if(aux->coluna > maxCol) maxCol = aux->coluna;
      aux = aux->abaixo;
    }

    // Imprimir todos os elementos, inclusive zeros
    for(int i = 0; i <= maxRow; i++){
      for(int j = 0; j <= maxCol; j++){
        std::cout << get(i, j) << " ";
      }
      std::cout << std::endl;
    }
  }
