#include <iostream>
#include <fstream>
#include <vector>
#include "SparseMatrix.h"
using namespace std;

void lerSparseMatrix(SparseMatrix& m, string arquivo){
string caminho = "../fileTests/" + arquivo;  

  ifstream arquivom(caminho); // abre e lê o arquivo

  if(!arquivom.is_open()){ // caso não seja possível abrir o arquivo
    cerr << "Erro ao ler o arquivo\n" << endl; // saída
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
    cout << "\n================================= HELP ===================================\n";
    cout << "sair ............... Fecha o Programa\n";
    cout << "criar m n ......... Cria uma nova matrix com m linhas e n colunas\n";
    cout << "mostrar i ............. Escreve a matrix i no terminal\n";
    cout << "mostraridx ............ Mostra todos os indixes das matrizes \n";
    cout << "soma i j ............ Soma as matrizes i e j do vetor de matrizes\n";
    cout << "multiplica i j ....... Multiplica as matrizes i e j do vetor de matrizes\n";
    cout << "limpar i ............ Limpa a matrix i\n";
    cout << "ler 'm.txt' ....... Lê a matrix esparsa do arquivo com nome de 'm.txt'\n";
    cout << "atualiza m i j value . Atualiza o valor da célula (i,j) na matrix m\n";
    cout << "limparTudo ........... Apaga todas as matrizes";
    cout << "\n=========================================================================\n";
}

int main() {
    vector<SparseMatrix> matrizes;
    string comando;
    string arquivo;
    int m, n, i, j;
    double value;

    do {
        opcoes();
        cin >> comando;

        if (comando == "sair") {
            cout << "\nSaindo...\n";
            break;
        } else if (comando == "criar") {
            cin >> m >> n;
            if (m > 0 && n > 0) {
                SparseMatrix novaMatriz(m, n);
                matrizes.push_back(novaMatriz);
                cout << "\nMatriz criada com sucesso. Índice: " << matrizes.size() - 1 << "\n";
            } else {
                cout << "\nDimensões inválidas!\n";
            }
        } else if (comando == "mostrar") {
            cin >> i;
            if (i >= 0 && i < matrizes.size()) {
                cout << "\nMatriz " << i << ":\n";
                matrizes[i].print();
            } else {
                cout << "\nÍndice inválido!\n";
            }
        } else if (comando == "mostraridx") {
            if(matrizes.empty()){
              cout << "\n O vetor de matrizes esta vazio.";
            } else{
              cout << "\nÍndices das matrizes:\n";
            }
            for (size_t k = 0; k < matrizes.size(); ++k) {
                cout << k << " ";
            }
            cout << "\n";
        } else if (comando == "soma") {
            cin >> i >> j;
            if (i >= 0 && i < matrizes.size() && j >= 0 && j < matrizes.size()) {
                SparseMatrix resultado = sum(matrizes[i], matrizes[j]);
                matrizes.push_back(resultado);
                cout << "\nResultado da soma armazenado no índice: " << matrizes.size() - 1 << "\n";
            } else {
                cout << "\nÍndices inválidos!\n";
            }
        } else if (comando == "multiplica") {
            cin >> i >> j;
            if (i >= 0 && i < matrizes.size() && j >= 0 && j < matrizes.size()) {
                SparseMatrix resultado = multiply(matrizes[i], matrizes[j]);
                matrizes.push_back(resultado);
                cout << "\nResultado da multiplicação armazenado no índice: " << matrizes.size() - 1 << "\n";
            } else {
                cout << "\nÍndices inválidos!\n";
            }
        } else if (comando == "limpar") {
            cin >> i;
            if (i >= 0 && i < matrizes.size()) {
                matrizes[i].clear();
                cout << "\nMatriz " << i << " limpa com sucesso.\n";
            } else {
                cout << "\nÍndice inválido!\n";
            }
        } else if (comando == "ler") {
            cin >> arquivo;
            SparseMatrix novaMatriz;
            lerSparseMatrix(novaMatriz, arquivo);
            matrizes.push_back(novaMatriz);
            cout << "\nMatriz carregada com sucesso. Índice: " << matrizes.size() - 1 << "\n";
        } else if (comando == "atualiza") {
            cin >> m >> i >> j >> value;
            if (m >= 0 && m < matrizes.size()) {
                matrizes[m].insert(i, j, value);
                cout << "\nValor atualizado com sucesso.\n";
            } else {
                cout << "\nÍndice inválido!\n";
            }
        } else if (comando == "limparTudo") {
            matrizes.clear();
            cout << "\nTodas as matrizes foram apagadas.\n";
        } else {
            cout << "\nComando inválido!\n";
        }
    } while (true);
}