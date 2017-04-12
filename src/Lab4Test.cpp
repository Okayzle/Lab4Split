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
    Map* mapPntr = new Map;
    mapPntr->load();
    return 0;
}
