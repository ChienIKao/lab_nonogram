#ifndef BOARD_H
#define BOARD_H

#include <unordered_set>
#include "Constants.h"
#include "Line.h"

class Board {
private:
    vector<Line> board;
    State state;
    unordered_set<short> painted;

public:
    Board();
};

#endif