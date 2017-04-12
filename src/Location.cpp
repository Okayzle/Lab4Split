/*
 * Location.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: thaokaye
 */
#include "Location.h"
#include <iostream>
using namespace std;
// all that we need is

/**
 * Constructor
 */
Location::Location(int row, int col, char token) {
    myRow = row;
    myCol = col;
    myToken = token;
    hasRob = false;
    myRobot = -1;
}

/**
 * Displays char at location
 */
char Location::display() {
    char retTok;
    if (hasRob) {
        retTok = myRobot + 48;
    } else if (hasMountain() == true) {
        retTok = '#';
    } else if (hasGold() == true) {
        retTok = '*';
    } else {
        retTok = token();
    }
    return retTok;
}

/**
 * sets a token
 */
void Location::setToken(int someNum){
    myToken = someNum + 48;
}

/**
 * sets a boolean and says the point was entered
 */
void Location::enter(int robotNumber) {
    hasRob = true;
    myRobot = robotNumber;
}

/**
 * check if has hold
 */
bool Location::hasGold() {
    bool check = false;
    if (myToken == '*')
        check = true;
    return check;
}

/**
 * check if has mountain
 */
bool Location::hasMountain() {
    bool check = false;
    if (myToken == '#')
        check = true;
    return check;
}

/**
 * checks if occupied
 */
bool Location::occupied() {
    return (hasRob == true || myToken == '#');
}

/**
 * check for if there is a robot in particular
 */
bool Location::hasRobot() {
    return hasRob;
}

/**
 * retrns col
 */
int Location::col() {
    return myCol;
}

/**
 * returns row
 */
int Location::row() {
    return myRow;
}

/**
 * takes gold
 */
void Location::takeGold() {
    myToken = ' ';
}

/**
 * marks that robot has left
 */
void Location::vacate() {
    hasRob = false;
    myRobot = -1;
}

/**
 * returns the token
 */
char Location::token() {
    return myToken;
}

