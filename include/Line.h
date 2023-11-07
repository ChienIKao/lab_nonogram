#ifndef LINE_H
#define LINE_H

#include "Constants.h"
#include "Description.h"

class Line {
private:
    LL bits;
    int index;
    vector<int> d;

public:
    Line(int index);
    bool fix(LL bits, vector<int> description, int lineLength, int descriptionIndex);
    bool fix0(LL bits, vector<int> description, int lineLength, int descriptionIndex);
    bool fix1(LL bits, vector<int> description, int lineLength, int descriptionIndex);
    int getBit(LL bits, int i);
    LL setBit(LL bits, int i, int value);
    LL getBits();
    LL getBits(LL bits, int start, int length);
    LL getDJ(int description);
};

#endif