#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include "Constants.h"
#include <fstream>
#include <string>

class Description {
private:
    ifstream fin;
    string CASE;
    vvInt description;       
public:
    Description();
    void openFile(string path);
    bool readFile();
    void closeFile();
    string getCase();
    vvInt getDescription();
};

#endif