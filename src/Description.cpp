#include "../include/Description.h"
#include <iostream>

Description::Description() {
    description = vvInt(BOARD_SIZE * 2);
}

void Description::openFile(string path) {
    fin.open(path);
    return ;
}

bool Description::readFile() {
    while (!fin.fail() && fin >> CASE) {
        CASE = CASE.substr(1);

        int i = 0, clue;    
        char symbol;
        while (i < BOARD_SIZE * 2) {
            fin >> clue;
            fin.get(symbol);
            description[i].push_back(clue);
            if (symbol == '\n') i++;
        }
        return true;
    }
    return false;
}

void Description::closeFile() {
    fin.close();
    return ;
}

string Description::getCase() {
    return CASE;
}

vvInt Description::getDescription() {
    return description;
}