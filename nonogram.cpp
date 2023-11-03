#include <iostream>
#include <fstream>
#include "include/Description.h"

using namespace std;

int main() {
    Description d = Description();
    d.openFile("input.txt");

    cout << "CASE: " << d.getCase() << "\n";
    while (d.readFile()) {
        
    }

    return 0;
}