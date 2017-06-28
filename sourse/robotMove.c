/*
 * Betribssicherheit
 * Aufgabe 2a Teil a
 * Robotorsteuerung in C
 *
 * 
 * File:   robotMove.c
 * Author: Rudolf
 *
 * Created on 19. Mai 2017, 14:47
 */

#include "robotMove.h"

typedef struct s_robot
{
   float l;  // Laenge der Roboterstange in Milimetern
   float d;  // Abstand des Endeffektors im Mittelpunkt zur Linearachse des Roboters in Milimetern
   float fi; // Schenkelwinkel des Dreieks in Grad
   
} robot;

static robot r;

motorPos init_motorPos(float a, float b, float c)
{
    motorPos mP;
    
    mP.a = a;
    mP.b = b;
    mP.c = c;
    
    return mP;
}

motorPos inverse(cartCoord cC)
{   
    motorPos mP;
    float l2 = (bot.l*bot.l);
    float radFi = bot.fi * 3.141592653 / 180;
    
    mP.a = sqrt(l2 - (cC.x*cC.x) - ((bot.d-cC.y)*(bot.d-cC.y)) ) +cC.z;
    mP.b = sqrt(l2 - ((-bot.d*sin(radFi)-cC.x)*(-bot.d*sin(radFi)-cC.x))- ((-bot.d*cos(radFi)-cC.y)*(-bot.d*cos(radFi)-cC.y))  ) +cC.z;
    mP.c = sqrt(l2 - ((bot.d*sin(radFi)-cC.x)*(bot.d*sin(radFi)-cC.x))- ((-bot.d*cos(radFi)-cC.y)*(-bot.d*cos(radFi)-cC.y))  ) +cC.z;
    
    return mP;
}

void linear(cartCoord start, cartCoord end,cartCoord *cC, int steps)
{
    
    
    cC[0] = start;
    cC[steps-1] = end;
    
}

void drive(motorPos *mP, int size)
{   
    int i;
    if(size < 1)
        printf("\nSize can't be less than one!\n");exit;
        
    for(i = 0; i < size; i++)
    {
        printf("%2d. Position:\n",i);
        printf("   a: %4f\n",mP[i].a);
        printf("   b: %4f\n",mP[i].b);
        printf("   c: %4f\n",mP[i].c);
    }
        printf("%f",bot.d);
}

void set_robot(float l, float d, float fi)
{
    r.l = l;
    r.d = d;
    r.fi = fi;
}
