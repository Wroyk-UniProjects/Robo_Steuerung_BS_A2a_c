/*
 * Betribssicherheit
 * Aufgabe 2a Teil a
 * Robotorsteuerung in C
 *
 * 
 * File:   robot.h
 * Author: Rudolf
 *
 * Created on 20. Mai 2017, 23:45
 */

#ifndef ROBOT_H
#define ROBOT_H


//Incudes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cartCoord.h"


typedef struct s_motorPos 
{
    double a,b,c;
}motorPos;


// Defins
motorPos init_motorPos(double a, double b, double c);
motorPos inverse(vector v, int rNum);
void inverseArray(vector *a_v, motorPos *a_mP, int size, int rNum);
void drive(motorPos *a_mP, int size, int rNum);
void set_robot(double l, double d, double fi, motorPos aktPos, int rNum);

#endif /* ROBOT_H */

