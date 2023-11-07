#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <vector>
#define BOARD_SIZE 25
#define U 0b11

using namespace std;

typedef enum State { SOLVED, CONFLICT, PAINTED, INCOMPLETE };
typedef vector<vector<int>> vvInt;
typedef unsigned long long LL;
typedef char Byte;

#endif