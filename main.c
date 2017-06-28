/*
 * Betribssicherheit
 * Aufgabe 2a Teil a
 * Robotorsteuerung in C
 *
 * 
 * File:   main.c
 * Author: Rudolf Baun
 *
 * Created on 19. Mai 2017, 14:47
 */

#include "header/robot.h"

#define SIZE 10
#define ROBOTONE 0

int main(void) {
    
    vector start = init_cartCoord(10.0,11.0,150.0);
    vector end = init_cartCoord(20.0,-10.0,160.0);
    vector v_array[SIZE];
    motorPos mP_array[SIZE];
    
    set_robot(233.0, 147.0, 60.0, init_motorPos(0,0,0), ROBOTONE);
    
    linear(start, end, v_array, SIZE);
    
    /*int i;
    for(i= 0; i < SIZE; i++)
        printCoord(v_array[i]);
    */
    
    inverseArray(v_array, mP_array, SIZE, ROBOTONE);
    
    drive(mP_array, SIZE, ROBOTONE);
    
    return (EXIT_SUCCESS);
}
