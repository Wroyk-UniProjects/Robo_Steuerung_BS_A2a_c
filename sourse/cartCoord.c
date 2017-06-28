/*
 * Betribssicherheit
 * Aufgabe 2a Teil a
 * Robotorsteuerung in C
 *
 * 
 * File:   cartCoord.c
 * Author: Rudolf
 *
 * Created on 20. Mai 2017, 23:07
 */

#include "../header/cartCoord.h"

vector init_cartCoord(double x, double y, double z)
{
    vector v;
    
    v.x = x;
    v.y = y;
    v.z = z;
    
    return v;
}

void linear(vector start, vector end, vector *a_v, int steps)
{   
    if(steps < 2)
    {
        printf("\nsteps can't be less than two!\n");return;
    }
    
    int i;
    vector dV;
    dV.x = (end.x-start.x)/(steps-1);
    dV.y = (end.y-start.y)/(steps-1);
    dV.z = (end.z-start.z)/(steps-1);
    
    a_v[0] = start;
    
    for(i = 0; i < steps-1; i++)
    {
       a_v[i+1].x = a_v[i].x+dV.x;
       a_v[i+1].y = a_v[i].y+dV.y;
       a_v[i+1].z = a_v[i].z+dV.z;
    }
    
}

void printCoord(vector v)
{
    printf("x: %4f\n", v.x);
    printf("y: %4f\n", v.y);
    printf("z: %4f\n", v.z);
}