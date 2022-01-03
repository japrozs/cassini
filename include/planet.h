#ifndef PLANET_H
#define PLANET_H

typedef struct {
	char* name;
	int windSpeeds; // km/h
	double relativeGravity; // relative to earth's gravity
	int temperature; // celsius
	double distanceFromEarth; // million km
	double orbitingSpeed; // km/s
	double axisTilt; // degrees
	double atmosphereDepth; // km 
} Planet;

Planet* newPlanet(char* name);
void printPlanet(Planet* planet);

#endif