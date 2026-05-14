// Copyright 2021 NNTU-CS
#include "main.h"

#include "alg.h"
#include <iostream>
#include <string>

int main() {
    BST<std::string> tree;
    const char* filename = "war_peace.txt";

    makeTree(tree, filename);
    std::cout << "Depth: " << tree.depth() << std::endl;
    std::cout << "pierre: " << tree.search("pierre") << std::endl;
    std::cout << "natasha: " << tree.search("natasha") << std::endl;
    std::cout << "andrew: " << tree.search("andrew") << std::endl;

    printFreq(tree);
    return 0;
}
