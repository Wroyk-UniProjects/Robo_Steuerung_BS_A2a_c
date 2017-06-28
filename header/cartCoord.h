/*
 * Betribssicherheit
 * Aufgabe 2a Teil a
 * Robotorsteuerung in C
 *
 * 
 * File:   cartCoord.h
 * Author: Rudolf
 *
 * Created on 19. Mai 2017, 14:47
 */

#ifndef CARTCOORD_H
#define CARTCOORD_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Typedefs
typedef struct s_vector 
{
   double x,y,z;
}vector;

// Defins
vector init_cartCoord(double x, double y, double z);
void linear(vector start, vector end,vector *v, int steps);
void printCoord(vector v);

#endif /* CARTCOORD_H */

