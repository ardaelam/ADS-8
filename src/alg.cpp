// Copyright 2021 NNTU-CS
// cpplint: disable=build/include_order
#include "bst.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string word;
    char ch;
    while (file.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ch = std::tolower(static_cast<unsigned char>(ch));
            word.push_back(ch);
        } else {
            if (!word.empty()) {
                tree.add(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tree.add(word);
    }
    file.close();
}

void printFreq(BST<std::string>& tree) {
    auto nodes = tree.getAllNodes();
    std::sort(nodes.begin(), nodes.end(),
        [](const std::pair<std::string, int>& a,
           const std::pair<std::string, int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

    for (const auto& p : nodes) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    std::ofstream out("result/freq.txt");
    if (!out) {
        std::cerr << "Не удалось создать result/freq.txt" << std::endl;
        return;
    }
    for (const auto& p : nodes) {
        out << p.first << " " << p.second << std::endl;
    }
    out.close();
}
