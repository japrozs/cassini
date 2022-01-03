#ifndef ROVER_H
#define ROVER_H

#include <stdbool.h>
#include <planet.h>

typedef struct {
	char* name;
	bool parachutesDeployed;
	bool thrustersOn;
	bool landed;
	double timeTaken;
} Rover;

Rover* newRover(char* name);
void launch(Rover* rover, Planet* planet);
void travel(Rover* rover, Planet* planet);
void printRover(Rover* rover);
void land(Rover* rover, Planet* planet);

#endif