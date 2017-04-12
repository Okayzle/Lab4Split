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
    int myRow, myCol, myRobot;
    char myToken;
    bool hasRob;

public:
    Location(int row, int col, char token);

    int col();
    int row();

    char display();
    char token();

    void setToken(int someNum);
    void enter(int RobotNum);
    void takeGold();
    void vacate();

    bool hasGold();
    bool hasMountain();
    bool occupied();
    bool hasRobot();

};

#endif /* LOCATION_H_ */
