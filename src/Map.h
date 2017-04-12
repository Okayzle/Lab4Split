/*
 * Map.h
 *
 *  Created on: Apr 7, 2017
 *      Author: thaokaye
 */


#ifndef MAP_H_
#define MAP_H_
#include <iostream>

class Robot;
class Location;

/**
 * This is the basic .h file interface
 */
class Map {

private:
    Robot *robobs[10];
    Location *locations[10][20];
    std::string robotBuilds[10];

    int maxNums, row, col, id, iterations, absIt;
    const int ASCCII_ALTER = 48;

    void checkAndMoveRobot(int j, std::string dirc, int len, int posi,
            int i, char cDirc);

public:

    // map and location checkers
    Map();
    bool canMoveTo(Location* destination);
    Location* locationAt(int row, int col);
    Location* eastOf(Location* source);
    Location* northOf(Location* source);
    Location* southOf(Location* source);
    Location* westOf(Location* source);

    // map methods
    void write();
    void load();
    void readMap();
    void MatrixAll(std::string Array[]);
    void readIterations();

    // robot methods
    void setMemNull();
    void makeRobots();
    void moveRobots();
    void printEnd();

};

#endif /* MAP_H_ */
