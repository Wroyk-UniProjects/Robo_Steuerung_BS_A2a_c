/*
 * Betribssicherheit
 * Aufgabe 2a Teil a
 * Robotorsteuerung in C
 *
 * 
 * File:   robot.c
 * Author: Rudolf
 *
 * Created on 20. Mai 2017, 23:45
 */

#include "../header/robot.h"

#define NUMBEROF 5
typedef struct s_robot
{
   double l;  // Laenge der Roboterstange in Milimetern
   double d;  // Abstand des Endeffektors im Mittelpunkt zur Linearachse des Roboters in Milimetern
   double fi; // Schenkelwinkel des Dreieks in Grad
   motorPos aktPos;
   
} robot;

static robot r[NUMBEROF];

motorPos init_motorPos(double a, double b, double c)
{
    motorPos mP;
    
    mP.a = a;
    mP.b = b;
    mP.c = c;
    
    return mP;
}

motorPos inverse(vector v, int rNum)
{   
    motorPos mP = init_motorPos(0,0,0);
    
    if(rNum < 0|| rNum >= NUMBEROF)
    {
        printf("\nRobot dosn't existst!\n"); return mP;
    }
    
    double l2 = (r[rNum].l*r[rNum].l);
    double radFi = r[rNum].fi * 3.141592653 / 180;
    
    
    mP.a = sqrt(l2 - (v.x*v.x) - ((r[rNum].d-v.y)*(r[rNum].d-v.y)) ) +v.z;
    mP.b = sqrt(l2 - ((-r[rNum].d*sin(radFi)-v.x)*(-r[rNum].d*sin(radFi)-v.x))- ((-r[rNum].d*cos(radFi)-v.y)*(-r[rNum].d*cos(radFi)-v.y))  ) +v.z;
    mP.c = sqrt(l2 - ((r[rNum].d*sin(radFi)-v.x)*(r[rNum].d*sin(radFi)-v.x))- ((-r[rNum].d*cos(radFi)-v.y)*(-r[rNum].d*cos(radFi)-v.y))  ) +v.z;
    
    return mP;
}

void inverseArray(vector *a_v, motorPos *a_mP, int size, int rNum)
{   
    int i;
    
    if(rNum < 0|| rNum >= NUMBEROF)
    {
        printf("\nRobot dosn't existst!\n");return;
    }
    for(i = 0; i < size;i++)
        a_mP[i] = inverse(a_v[i], rNum);
}

void drive(motorPos *a_mP, int steps,int rNum)
{   
    int i;
    
    if(rNum < 0|| rNum >= NUMBEROF)
    {
        printf("\nRobot dosn't existst!\n");return;
    }
    
    if(steps < 1)
    {
        printf("\nSize can't be less than one!\n");return;
    }
    
    for(i = 0; i < steps; i++)
    {   
        r[rNum].aktPos = a_mP[i];
        
        printf("%2d. Position:\n",i+1);
        printf("   a: %4f\n", a_mP[i].a);
        printf("   b: %4f\n", a_mP[i].b);
        printf("   c: %4f\n", a_mP[i].c);
    }
}

void set_robot(double l, double d, double fi ,motorPos aktPos, int rNum)
{
    if(rNum < 0|| rNum >=  NUMBEROF)
    {
        printf("\n Only %d robots are alowd!\n      Starting with 0.\n",NUMBEROF);return;
    }
    r[rNum].l = l;
    r[rNum].d = d;
    r[rNum].fi = fi;
    r[rNum].aktPos = aktPos;
}