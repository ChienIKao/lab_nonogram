#include <iostream>
#include <fstream>
#include "include/Line.h"

using namespace std;

int main() {
    Description d = Description();
    d.openFile("input.txt");

    while (d.readFile()) {
        cout << "CASE: " << d.getCase() << "\n";

        Line line = Line(0);

        LL l = line.getBits();

        cout << "BITS: \n";
        for (int i=0; i<=BOARD_SIZE; i++) 
            cout << i << " : "<< line.getBit(l, i) << endl;
        break;
    }

    return 0;
}