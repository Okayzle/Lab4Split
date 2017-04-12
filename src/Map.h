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

    Location *locations[10][20];
    std::string robotBuilds[10];
    Robot *robobs[10];
    //Robot *robotList[10];
    int maxNums;
    int row;
    int col;
    // NEW- special id for robot, numbers 0-9
    int id;
    int iterations;
    const int ASCCII_ALTER = 48;

public:

    Map();

    bool canMoveTo(Location* destination);
    Location* locationAt(int row, int col);
    Location* eastOf(Location* source);
    Location* northOf(Location* source);
    Location* southOf(Location* source);
    Location* westOf(Location* source);
    void write();
    // for the new map, I will have to alter the load method, see .cpp for details
    void load();
    // these are the new methods where we will load in the new data
    void readMap();
    void readIterations();
    void readRobots();
    void makeRobots();

    void setRobCords(int num, int num2);
    int getRobRow();
    int getRobCol();

    void MatrixAll(std::string Array[]);
    void moveRobots();
    void setMemNull();
    void moveOneRobot();
    //TODO: REMOVE
    void printME();

};

#endif /* MAP_H_ */
