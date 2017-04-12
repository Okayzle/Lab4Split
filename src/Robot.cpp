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

/**
 * returns row
 */
int Robot::retMyRow() {
    return myRow;
}

/**
 * returns col
 */
int Robot::retMyCol() {
    return myCol;
}

/**
 * returns id
 */
int Robot::retMyId() {
    return myId;
}

/**
 * returns gold amount
 */
int Robot::retMyGold() {
    return gold;
}

/**
 * returns direction string
 */
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
 *
 * Write the Robot's status to standard output using the format
 * Robot at row, column (amount gold)
 */
void Robot::displayStatus() {
    cout << "Robot at " << myRow << ", " << myCol << " (" << gold
            << " gold) at step " << step << endl;
}

/**
 * prints end method, I added this to keep it for the end
 */
void Robot::atEnd() {
    cout << "Robot at " << myRow << ", " << myCol << " (" << gold << " gold)"
            << endl;
    // myMap->write();
}

/**
 * Prints Error status
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
 *
 * I am well aware that this method is beyond 30 lines
 */
bool Robot::move(char direc, int inStep) {
    step = inStep;
    bool robMoved = false;
    Location* myNewPoint;

    switch (direc) {
    case 'n':
        myNewPoint = myMap->northOf(myPoint);
        robMoved = isPointValid(robMoved, myNewPoint, direc);
        break;

    case 's':
        myNewPoint = myMap->southOf(myPoint);
        robMoved = isPointValid(robMoved, myNewPoint, direc);
        break;

    case 'e':
        myNewPoint = myMap->eastOf(myPoint);
        robMoved = isPointValid(robMoved, myNewPoint, direc);
        break;

    case 'w':
        myNewPoint = myMap->westOf(myPoint);
        robMoved = isPointValid(robMoved, myNewPoint, direc);
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
        cout << "What happened barusu?" << endl;
        robMoved = false;
    }
    return robMoved;
}

void Robot::goldCheck(Location* myNewPoint) {
    // and if we find gold we take the gold
    bool hasGold = myNewPoint->hasGold();
    if (hasGold == true) {
        myNewPoint->takeGold();
        gold = gold + 1;
    }
}

/**
 * Helper method to check if the point we are attempting to move to is valid
 */
bool Robot::isPointValid(bool robMoved, Location* myNewPoint, char dirc) {
    // if we did not return a null and the point is not occupied
    if (myNewPoint != NULL && !myNewPoint->occupied()) {
        // we leave our current point
        myPoint->vacate();
        // we say we moved
        robMoved = true;
        // and if we find gold we take the gold
        goldCheck(myNewPoint);
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

void Robot::restartingLifeInAnotherWorldFromZero() {
    // we we start life again, we say we have a robot
    myPoint->enter(myId);
    // if the point has gold, we take it
    goldCheck(myPoint);
}

