#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#define BOARD_SIZE 25

using namespace std;

typedef enum State { SOLVED, CONFLICT, PAINTED, INCOMPLETE };
typedef vector<vector<int>> vvInt;

#endif