#include "BTreeNode.h"

#include <iostream>

using namespace std;

// Construtor de BTreeNode
BTreeNode::BTreeNode(int t, bool isLeaf) {
    this->t = t;
    this->isLeaf = isLeaf;
    keys = new int[2 * t - 1];
    children = new BTreeNode*[2 * t];
    n = 0;
}

// Função para inserir uma chave em um nó que não está cheio
void BTreeNode::insertNonFull(int key) {
    int i = n - 1;
    if (isLeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        n++;
    } else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        i++;
        if (children[i]->n == 2 * t - 1) {
            splitChild(i, children[i]);
            if (keys[i] < key) {
                i++;
            }
        }
        children[i]->insertNonFull(key);
    }
}

// Função para dividir um nó cheio
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->isLeaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }
    if (!y->isLeaf) {
        for (int j = 0; j < t; j++) {
            z->children[j] = y->children[j + t];
        }
    }
    y->n = t - 1;
    for (int j = n; j > i; j--) {
        children[j + 1] = children[j];
    }
    children[i + 1] = z;
    for (int j = n - 1; j > i; j--) {
        keys[j + 1] = keys[j];
    }
    keys[i] = y->keys[t - 1];
    n++;
}

// Função para percorrer a árvore
void BTreeNode::traverse() {
    int i = 0;
    while (i < n) {
        if (!isLeaf) {
            children[i]->traverse();
        }
        cout << keys[i] << " ";
        i++;
    }
    if (!isLeaf) {
        children[i]->traverse();
    }
}

// Função para buscar uma chave na árvore
BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < n && key > keys[i]) {
        i++;
    }
    if (i < n && key == keys[i]) {
        return this;
    }
    if (isLeaf) {
        return nullptr;
    }
    return children[i]->search(key);
}
