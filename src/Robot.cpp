/*
 * Robot.cpp

 *
 *  Created on: Apr 7, 2017
 *      Author: thaokaye
 */
#include "Map.h"
#include "Location.h"
#include "Robot.h"
#include <iostream>
using namespace std;

/**
 * Basic Constructor
 */
Robot::Robot(Map* map, int startRow, int startCol, string directions, int id) {
    myMap = map;
    myRow = startRow;
    myCol = startCol;
    myPoint = (map->locationAt(myRow, myCol));
    gold = 0;
    myDirections = directions;
    myId = id;
    step = 0;
    restartingLifeInAnotherWorldFromZero();
}

int Robot::retMyRow() {
    return myRow;
}

int Robot::retMyCol() {
    return myCol;
}
int Robot::retMyId() {
    return myId;
}
int Robot::retMyGold() {
    return gold;
}

std::string Robot::retMyDirc() {
    return myDirections;
}

/*
 * Returns the map of the world in which the robot is moving around.
 */
Map* Robot::map() {
    return myMap;
}

/**
 * Reads the rest of the input
 * Lines: 7
 */
void Robot::readRest() {
    char direction;
    while (cin >> direction) {
        // if we did not move
        //if (move(direction) == false) {
        //  errorStatus(direction);
        //break;
        //}
    }
}

/**
 * this would be like the robot looking at the map and gathering information about what he knows
 * functions as another main
 * Lines: 7
 */
void Robot::lookAtMap() {
    // rob loads the map from the constructor
    Map *mapper = map();
    // rob finds his location and remembers it
    // myRow = mapper->getRobRow();
    // myCol = mapper->getRobCol();
    // point work
    // myPoint = mapper->locationAt(myRow, myCol);

    myPoint->enter(myId);
    if (myPoint->hasGold()) {
        myPoint->takeGold();
        ++gold;
    }

    // Rob reads the rest of the map
    readRest();
    atEnd();
}

/**
 *
 * Write the Robot's status to standard output using the format
 * Robot at row, column (amount gold)
 * Lines: 1
 */
void Robot::displayStatus() {
    cout << "Robot at " << myRow << ", " << myCol << " (" << gold
            << " gold) at step " << step << endl;
}

/**
 * prints end method, I added this to keep it for the end
 * Lines: 3
 */
void Robot::atEnd() {
    // prints out something like:
    // At end:
    // Robot at 7, 6 (1 gold)
    cout << "Robot at " << myRow << ", " << myCol << " (" << gold << " gold)"
            << endl;
    // myMap->write();
}

/**
 * Prints Error status
 * Line: 3
 */
void Robot::errorStatus(char dir) {
    // Prints out something like: Error: robot status Robot at 7, 6 (1 gold) will not allow moving w
    cout << "Error in step " << step << ": robot " << myId << " cannot move "
            << dir << endl;
}

/**
 * Move the robot one location in the specified direction (east, west, north, south). Returns true if the robot moves,
 * false if moving the robot would make it exit the map or climb a mountain. This method should also ensure the robot
 * picks up any gold that it encounters.
 * Lines: 30 it's a switch, so it should be okay...
 * TODO: REFRACTOR
 */
bool Robot::move(char direc, int inStep) {
    step = inStep;
    bool robMoved = false;
    Location* myNewPoint;

    switch (direc) {
    case 'n':
        myNewPoint = myMap->northOf(myPoint);
        robMoved = isPointNull(robMoved, myNewPoint, direc);
        break;

    case 's':
        myNewPoint = myMap->southOf(myPoint);
        robMoved = isPointNull(robMoved, myNewPoint, direc);
        break;

    case 'e':
        myNewPoint = myMap->eastOf(myPoint);
        robMoved = isPointNull(robMoved, myNewPoint, direc);
        break;

    case 'w':
        myNewPoint = myMap->westOf(myPoint);
        robMoved = isPointNull(robMoved, myNewPoint, direc);
        break;

    case 'p':
        myMap->write();
        robMoved = true;
        break;

    case '?':
        displayStatus();
        robMoved = true;
        break;

    default:
        cout << "What happened playa?" << endl;
        robMoved = false;
    }
    return robMoved;
}

bool Robot::isPointNull(bool robMoved, Location* myNewPoint, char dirc) {
    // if we did not return a null and the point is not occupied
    if (myNewPoint != NULL && !myNewPoint->occupied()) {
        // we leave our current point
        myPoint->vacate();
        // we say we moved
        robMoved = true;
        // and if we find gold we take the gold
        bool hasGold = myNewPoint->hasGold();
        if (hasGold == true) {
            myNewPoint->takeGold();
            gold = gold + 1;
        }
        // we say that our new point is now our point
        myPoint = myNewPoint;
        // we enter that point
        myPoint->enter(myId);
        // we reset our rows and cols
        myCol = myPoint->col();
        myRow = myPoint->row();
        // if the point is null
    } else {
        errorStatus(dirc);
        awakeAndAlive = false;
        robMoved = false;
    }

    return robMoved;
}

bool Robot::isWoke() {
    return awakeAndAlive;
}

void Robot::pointCheck() {
    cout << myPoint->row() << myPoint->col() << " ";
}

void Robot::restartingLifeInAnotherWorldFromZero() {
    // we we start life again, we say we have a robot
    myPoint->enter(myId);
    // if the point has gold, we take it
    bool hasGold = myPoint->hasGold();
    if (hasGold == true) {
        myPoint->takeGold();
        gold = gold + 1;
    }

    //
}

