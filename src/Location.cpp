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

Location::Location(int row, int col, char token) {
    myRow = row;
    myCol = col;
    myToken = token;
    hasRob = false;
    myRobot = -1;
}

int Location::col() {
    return myCol;
}

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

void Location::setToken(int someNum){
    myToken = someNum + 48;
}

void Location::enter(int robotNumber) {
    hasRob = true;
    myRobot = robotNumber;
}

bool Location::hasGold() {
    bool check = false;
    if (myToken == '*')
        check = true;
    return check;
}

bool Location::hasMountain() {
    bool check = false;
    if (myToken == '#')
        check = true;
    return check;
}

bool Location::occupied() {
    return (hasRob == true || myToken == '#');
}

bool Location::hasRobot() {
    return hasRob;
}

int Location::row() {
    return myRow;
}

void Location::takeGold() {
    myToken = ' ';
}

void Location::vacate() {
    hasRob = false;
    myRobot = -1;
}

char Location::token() {
    return myToken;
}

