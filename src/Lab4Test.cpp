//============================================================================
// Name        : Lab4.cpp
// Author      : Kay Thao
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Robot.h"
#include "Map.h"
using namespace std;

int main() {
    // Rob begins his journey not knowing where he is.
    //    int row = 0;
    //    int col = 0;
    Map* mapPntr = new Map;

    mapPntr->load();
    // Robot robHasker(mapPntr, row, col);
    // but with a map, he can do it!
    // robHasker.lookAtMap();

    return 0;
}
