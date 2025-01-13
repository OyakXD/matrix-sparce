#ifndef NODE_H
#define NODE_H

struct Node {
  Node *direita;
  Node *abaixo;
  int linha;
  int coluna;
  double valor;

  Node() = default;
};

#endif