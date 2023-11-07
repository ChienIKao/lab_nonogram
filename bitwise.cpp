#include <bits/stdc++.h>

using namespace std;

typedef char Byte;

int getBit(Byte bits, int i) {
    int idx = 7 - i * 2;

    return ((bits & (1 << idx)) > 0) * 2 + ((bits & (1 << (idx - 1))) > 0);
}

bool getBitValue(Byte bits, int i) {
    return (bits & (1 << i)) > 0;
}

Byte setBit(Byte bits, int i, int value) {
    int idx = 7 - i * 2;
    Byte mask1 = ~(1 << idx);
    Byte mask2 = ~(1 << (idx - 1));

    if (value == 3) {
        bits |= (1 << idx);
        bits |= (1 << (idx - 1));
    } else if (value == 1 || value == 2) {
        bits |= (1 << idx);
        bits &= mask2;
    } else {
        bits &= mask1;
        bits &= mask2;
    }

    return bits;
}

Byte getDJ(int d) {
    Byte dj = (1 << (2 * d + 3)) - 1;
    dj = setBit(dj, 0, 0);
    for (int i=1; i<=d+1; i++) {
        dj = setBit(dj, i, 1);
    }
    return dj;
}

int main () {
    Byte bits = getDJ(2);
    
    Byte b = 0b11111111;
    b = ~b;
    for (int i=7; i>=0; i--) {
        cout << getBitValue(b, i) << " ";
    }

    return 0;
}