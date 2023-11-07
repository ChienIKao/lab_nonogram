#include "../include/Line.h"

Line::Line(int i) {
    this->bits = (1LL<<52) - 1;
    this->bits = setBit(this->bits, 0, 0);
    index = i;
    d = Description().getDescription()[index];
}

bool Line::fix(LL bits, vector<int> description, int lineLength, int descriptionIndex) {
    if (lineLength == 0 && descriptionIndex == -1) return true;
    else if (lineLength == 0 && descriptionIndex >= 0) return false;
    return fix0(bits, description, lineLength, descriptionIndex) || fix1(bits, description, lineLength, descriptionIndex);
}

bool Line::fix0(LL bits, vector<int> description, int lineLength, int descriptionIndex) {
    if (getBit(bits, lineLength - 1) == 0 || getBit(bits, lineLength - 1) == U) 
        return fix(bits, description, lineLength - 1, descriptionIndex);
    return false; 
}

bool Line::fix1(LL bits, vector<int> description, int lineLength, int descriptionIndex) {
    if (descriptionIndex >= 0 && lineLength >= d[descriptionIndex] + 1) {
        if (getBits(bits, lineLength - d[descriptionIndex] - 1, lineLength) == getDJ(d[descriptionIndex])) 
            return fix(bits, description, lineLength - d[descriptionIndex] - 1, descriptionIndex - 1);
    }
    return false;
}

int Line::getBit(LL bits, int i) {
    int idx = ((BOARD_SIZE + 1) * 2) - 1 - i * 2;

    return ((bits & (1 << idx)) > 0) * 2 + ((bits & (1 << (idx - 1))) > 0);
}

LL Line::setBit(LL bits, int i, int value) {
    int idx = ((BOARD_SIZE + 1) * 2) - 1 - i * 2;

    cout << "index " << idx << endl;
    cout << "index - 1 " << idx - 1 << endl;

    LL mask1 = ~(1 << idx);
    LL mask2 = ~(1 << (idx - 1)); 

    if (value == 3) { // U
        bits |= (1 << idx);
        bits |= (1 << (idx - 1));
    } else if (value == 1 || value == 2) { // 1
        bits |= (1 << idx);
        bits &= mask2;
    } else { // 0
        bits &= mask1;
        bits &= mask2;
    }

    return bits;
}

LL Line::getBits() {
    return this->bits;
}

LL Line::getBits(LL bits, int start, int length) {
    LL res = 0;
    for (int idx=start; idx<=length; idx++) {
        res += getBit(bits, idx);
    }
    return res;
}

LL Line::getDJ(int description) {
    LL dj = (1 << (2 * description + 3)) - 1;
    dj = setBit(dj, 0, 0);
    for (int i=1; i<=description+1; i++) {
        dj = setBit(dj, i, 1);
    }
    return dj;
}