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
    int t;                 // Ordem da �rvore
    int n;                 // N�mero de chaves no n�
    bool isLeaf;          // Indica se o n� � folha

    BTreeNode(int t, bool isLeaf);  // Construtor

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
    void traverse();
    BTreeNode* search(int key);
};
#endif // BTREENODE_H
