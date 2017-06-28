/*
 * Betribssicherheit
 * Aufgabe 2a Teil a
 * Robotorsteuerung in C
 *
 * 
 * File:   robotMove.h
 * Author: Rudolf
 *
 * Created on 19. Mai 2017, 14:47
 */

#ifndef ROBOTMOVE_H
#define ROBOTMOVE_H

typedef struct s_motorPos 
{
    float a,b,c;
}motorPos;

//Incudes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cartCoord.h"

// Defins
motorPos init_motorPos(float a, float b, float c);
motorPos inverse(cartCoord cC);
void drive(motorPos *mP, int size);
void set_robot(float l, float d, float fi);

#endif /* ROBOTMOVE_H */

