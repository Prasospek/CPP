//
// Created by Koty97 on 29.10.2020.
//

#ifndef TEST1_LOADER_H
#define TEST1_LOADER_H

#include <fstream>
#include <array>

class Loader {
    std::string filePath;
public:
    Loader(std::string path);

    std::array<std::array<int,4>,4>loadFile();

};


#endif //TEST1_LOADER_H
