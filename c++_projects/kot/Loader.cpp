//
// Created by Koty97 on 29.10.2020.
//

#include "Loader.h"
#include <iostream>

std::array<std::array<int, 4>, 4> Loader::loadFile() {
    std::array<std::array<int, 4>, 4> board;
    std::ifstream *file = new std::ifstream(this->filePath);
    if (!file->is_open()) {
        throw std::invalid_argument("There was error while opening " + this->filePath);
    }
    std::string line;
    int i = 0;
    int j = 0;
    while (getline(*file, line)) {
        for (char c:line) {
                board.at(i).at(j) =(int)c-48;//exception
            j++;
        }
        i++;
        j = 0;
    }
    file->close();
    return board;
}

Loader::Loader(std::string path) {
    filePath = path;
}
