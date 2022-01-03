#include <stdio.h>
#include <stdlib.h>
#include <planet.h>

Planet* newPlanet(char* name){
	Planet* planet = malloc(sizeof(Planet));
	if(planet == NULL){
		printf("🛑 Couldn't allocate memory for a new planet\n");
		exit(1);
	}
	planet->name = name;

	return planet;
}

void printPlanet(Planet* planet){
	printf(
		"========= Planet information =========\n\n"
		"  Name                    :: %s\n"
		"  Wind Speeds             :: %d\n"
		"  Relative Gravity Speeds :: %f\n"
		"  Temperature             :: %d\n"
		"  Distance from Earth     :: %f\n"
		"  Orbiting Speed          :: %f\n"
		"  Axis Tilt               :: %f\n"
		"  Atmosphere Height       :: %f\n\n"
		"====================================\n",
		planet->name, planet->windSpeeds, planet->relativeGravity, planet->temperature,
		planet->distanceFromEarth, planet->orbitingSpeed, planet->axisTilt,
		planet->atmosphereDepth
	);
}