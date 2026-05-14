// Copyright 2021 NNTU-CS
// cpplint: disable=build/include_order
#include "bst.h"

#include <iostream>
#include <string>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> tree;
    const char* filename = "src/war_peace.txt";   // измени при необходимости

    makeTree(tree, filename);
    std::cout << "Depth: " << tree.depth() << std::endl;
    std::cout << "pierre: " << tree.search("pierre") << std::endl;
    std::cout << "natasha: " << tree.search("natasha") << std::endl;
    std::cout << "andrew: " << tree.search("andrew") << std::endl;

    printFreq(tree);
    return 0;
}
