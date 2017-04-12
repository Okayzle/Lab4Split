/*
 * Location.h
 *
 *  Created on: Apr 7, 2017
 *      Author: thaokaye
 */

#ifndef LOCATION_H_
#define LOCATION_H_

class Location {

private:
    int myRow;
    int myCol;
    int myRobot;
    char myToken;

public:
    bool hasRob;

    Location(int row, int col, char token);
    void setToken(int someNum);

    int col();
    int row();
    char display();
    char token();
    void enter(int RobotNum);
    void takeGold();
    void vacate();
    bool hasGold();
    bool hasMountain();
    bool occupied();
    bool hasRobot();

};

#endif /* LOCATION_H_ */
