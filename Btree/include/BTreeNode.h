#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class BTreeNode {
public:
    int* keys;            // Array de chaves
    BTreeNode** children; // Ponteiros para os filhos
    int t;                 // Ordem da árvore
    int n;                 // Número de chaves no nó
    bool isLeaf;          // Indica se o nó é folha

    BTreeNode(int t, bool isLeaf);  // Construtor

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
    void traverse();
    BTreeNode* search(int key);
};
#endif // BTREENODE_H
