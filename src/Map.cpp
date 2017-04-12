/*
 * Map.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: thaokaye
 */
#include "Map.h"
#include "Location.h"
#include "Robot.h"
#include <iostream>
#include <string>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */

using namespace std;

/**
 * A map of all locations. Store the locations as a two-dimensional array, probably Locations *locations[HEIGHT][WIDTH].
 */

Map::Map() {
    col = 0;
    row = 0;
    maxNums = 100;
    iterations = 0;
    id = -1;

}

/**
 * Return true if a robot can move into a destination location (there's no robot
 * there and no mountain).
 * Lines: 5
 */
bool Map::canMoveTo(Location* destination) {
    bool canMove = false;
    // if we are not at a mountain and we don't have rob, we can move
    if ((destination->token() != '#') || !(destination->hasRobot())) {
        canMove = true;
    }
    return canMove;
}

/**
 * Return the location to the east of the source location, or nullptr if the east
 * is at a wall.
 * Lines: 6
 */
Location* Map::eastOf(Location* source) {
    int row = source->row();
    int col = source->col() + 1;

    if (col > 19)
        return NULL;
    else
        return locations[row][col];
}

/**
 * returns the location at that point
 * Lines: 1
 */
Location* Map::locationAt(int row, int col) {
    return locations[row][col];
}

/**
 * Return the location to the north of the source location, or nullptr if that
 * location is a wall.
 * Check elsewhere for the location
 * Lines: 6
 */
Location* Map::northOf(Location* source) {
    int row = source->row() - 1;
    int col = source->col();

    if (row < 0)
        return NULL;
    else
        return locations[row][col];
}

/**
 * Return the location to the south of the source location, or nullptr if that
 * location is a wall.
 * Lines: 6
 */
Location* Map::southOf(Location* source) {
    int row = source->row() + 1;
    int col = source->col();

    if (row > 9)
        return NULL;
    else
        return locations[row][col];
}

/**
 * Return the location to the west of the source location, or nullptr if that
 * location is a wall.
 * Lines: 6
 */
Location* Map::westOf(Location* source) {
    int row = source->row();
    int col = source->col() - 1;

    if (col < 0)
        return NULL;
    else
        return locations[row][col];
}

/**
 * Write the map to standard output using the same format as load (with the
 * exception that the robot's position is marked by R).
 * Lines: 9
 */
void Map::write() {
    cout << "+--------------------+" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "|";
        for (int j = 0; j < 20; ++j) {
            char temp = locations[i][j]->display();
            cout << temp;
        }
        cout << "|" << endl;
    }
    cout << "+--------------------+" << endl;
}

/**
 * Read the map from standard input, setting up the location data as required.
 * Lines: 13
 */
void Map::load() {
    setMemNull();
    readMap();
    readIterations();
    // at this point the map has been read, the iterations has been stored, and the directions to build the robots has been stored
    makeRobots();
    // printME();

    // we get to here
    moveRobots();
    //moveOneRobot();

}

/**
 * this method ensures that the entire method is set to null
 */
void Map::setMemNull() {
    for (int i = 0; i < 10; ++i) {
        robobs[i] = nullptr;
    }
}

void Map::printME() {
    for (int i = 0; i < 10; ++i) {
        if (robobs[i] == nullptr) {
            // do  nothing
        } else {
            cout << robobs[i]->isWoke() << endl;
        }
    }
    cout << "lol";
}

void Map::moveRobots() {
    std::string dirc;
    int len, posi, absIt;
    char cDirc;
    absIt = abs(iterations);
    // for each iteration
    for (int i = 0; i <= absIt - 1; ++i) {
        // cout << i << ": ";
        // for each robot
        if (iterations < 0 ){
            write();
        }
        for (int j = 0; j < 10; ++j) {
            if (robobs[j] != nullptr && robobs[j]->isWoke()) {
                // get the robot directions and
                dirc = robobs[j]->retMyDirc();
                len = dirc.length();
                posi = (i % len);
                cDirc = dirc[posi];

                // this crashes!!!
                robobs[j]->move(cDirc, i);
            }
        }
    }

    cout << "At end:" << endl;
    for (int i = 0; i < 10; ++i) {
        if (robobs[i] != nullptr) {
            robobs[i]->atEnd();
        }
    }

    write();
}

// STUB
void Map::moveOneRobot() {
    for (int i = 0; i < 10; ++i) {
        robobs[i]->pointCheck();
    }
}

void Map::makeRobots() {
    int row, col, id, cntr = 0;
    std::string directions = "";

    cntr = 0;
    // read first robots
    cin >> id;

    while (cin) {
        // make the robot with the new values
        cin >> row;
        cin >> col;
        cin >> directions;
        robobs[cntr] = new Robot(this, row, col, directions, id);
        ++cntr;

        cin >> id;
    }
}

void Map::readMap() {
    string arrayLines[maxNums], locationLines[9], line;
    getline(cin, line);
    int ptr = 0;
    while (cin && ptr != 11) {
        arrayLines[ptr] = line;
        getline(cin, line);
        ++ptr;
    }
    // this loop will remove the locations to a seperate array
    for (int i = 1; i < 10; ++i) {
        // this sets the location lines to the values of 1-10 values
        locationLines[i - 1] = arrayLines[i];
    }
    MatrixAll(arrayLines);
}

/**
 * Reads and sets the iterations
 */
void Map::readIterations() {
    cin >> iterations;
    // cout << iterations << " Wow!" << endl;
}

// TODO: REMOVE!!!
void Map::readRobots() {
    string line;
    int ptr = 0;
    getline(cin, line);
    while (cin && ptr <= 10) {
        robotBuilds[ptr] = line;
        // cout << line;
        getline(cin, line);
        ++ptr;
    }

}

/**
 * set coordinates
 * Lines: 2
 */
void Map::setRobCords(int num, int num2) {
    row = num;
    col = num2;
}

/**
 * gets row
 * Lines: 1
 */
int Map::getRobRow() {
    return row;
}

/**
 * gets column
 * Lines: 1
 */
int Map::getRobCol() {
    return col;
}

/**
 * Puts all the data into a 2-d array
 * Lines: 7
 */
void Map::MatrixAll(string Array[]) {
    for (int i = 1; i <= 10; ++i) {
        // this takes the line from the array
        string temp = Array[i];
        for (int j = 1; j <= 20; ++j) {
            // this parses the entire line into it's pieces then to locations
            locations[i - 1][j - 1] = new Location(i - 1, j - 1, temp[j]); // actual location stored
        }
    }
}

