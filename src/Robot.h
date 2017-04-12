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
    std::string myDirections;

    int myRow, myCol, gold, myId, step;
    bool awakeAndAlive = true;

    bool isPointValid(bool robMoved, Location* myNewPoint, char dirc);
    void goldCheck(Location* myNewPoint);
    bool nextPointCheck(char direc);

    // if you get this stupid reference, hit me up!
    void restartingLifeInAnotherWorldFromZero();


public:
    Robot(Map* map, int startRow, int startCol, std::string directions, int id);
    Map* map();

    // self methods-
    void displayStatus();
    void atEnd();
    void errorStatus(char dir);

    // movement methods
    bool move(char direc, int step);
    bool isWoke();

    // return methods
    std::string retMyDirc();
    int retMyRow();
    int retMyCol();
    int retMyId();
    int retMyGold();
};


#endif /* ROBOT_H_ */
