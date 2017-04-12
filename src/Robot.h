/*
 * Robot.h
 *
 *  Created on: Apr 7, 2017
 *      Author: thaokaye
 */

#ifndef ROBOT_H_
#define ROBOT_H_
#include "Location.h"
#include "Map.h"

class Robot{

private:
    Map* myMap;
    Location* myPoint;

    int myRow;
    int myCol;
    int gold;
    int myId;
    int step;
    std::string myDirections;
    bool awakeAndAlive = true;

    bool isPointNull(bool robMoved, Location* myNewPoint, char dirc);
    void restartingLifeInAnotherWorldFromZero();

public:
    Robot(Map* map, int startRow, int startCol, std::string directions, int id);
    Map* map();
    void readRest();
    void lookAtMap();
    void displayStatus();
    void atEnd();
    void errorStatus(char dir);
    bool move(char direc, int step);
    bool isWoke();

    std::string retMyDirc();
    int retMyRow();
    int retMyCol();
    int retMyId();
    int retMyGold();
    void pointCheck();

};


#endif /* ROBOT_H_ */
