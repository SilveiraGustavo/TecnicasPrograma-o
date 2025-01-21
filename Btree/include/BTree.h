#ifndef BTREE_H
#define BTREE_H

#include <BTreeNode.h>
class BTree {
public:
    BTreeNode* root;
    int t; // Ordem da árvore

    BTree(int t);
    void insert(int key);
    void traverse();
    BTreeNode* search(int key);
    void exportToFile(const std::string& outputFile);
    void exportHelper(BTreeNode* node, std::ofstream& outFile);
    void loadFromInputFile(const std::string& inputFile);

};
#endif // BTREE_H
