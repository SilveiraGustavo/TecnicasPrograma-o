#include "BTree.h"
#include <iostream>
#include <fstream>

using namespace std;

// Construtor de BTree
BTree::BTree(int t) {
    root = new BTreeNode(t, true);
    this->t = t;
}

// Função para inserir uma chave na árvore B
void BTree::insert(int key) {
    if (root->n == 2 * t - 1) {
        BTreeNode* s = new BTreeNode(t, false);
        s->children[0] = root;
        s->splitChild(0, root);
        root = s;
    }
    root->insertNonFull(key);
}

// Função para percorrer a árvore B
void BTree::traverse() {
    root->traverse();
    cout << endl;
}

// Função para buscar uma chave na árvore B
BTreeNode* BTree::search(int key) {
    return root->search(key);
}

// Função para exportar os dados para um arquivo
void BTree::exportToFile(const string& outputFile) {
    ofstream outFile(outputFile);
    if (outFile.is_open()) {
        exportHelper(root, outFile);
        outFile.close();
    } else {
        cout << "Erro ao abrir o arquivo para exportação!" << endl;
    }
}

// Função auxiliar para exportar a árvore para um arquivo
void BTree::exportHelper(BTreeNode* node, ofstream& outFile) {
    int i = 0;
    while (i < node->n) {
        if (!node->isLeaf) {
            exportHelper(node->children[i], outFile);
        }
        outFile << node->keys[i] << " ";
        i++;
    }
    if (!node->isLeaf) {
        exportHelper(node->children[i], outFile);
    }
}

void BTree::loadFromInputFile(const string& inputFile) {
    ifstream inFile(inputFile);
    if (inFile.is_open()) {
        int key;
        while (inFile >> key) {
            insert(key);
        }
        inFile.close();
    } else {
        cout << "Erro ao abrir o arquivo de entrada!" << endl;
    }
}
