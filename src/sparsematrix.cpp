#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(){
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