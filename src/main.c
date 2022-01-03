#include <stdio.h>
#include <cassini.h>
#include <planet.h>
#include <rover.h>
#include <stdlib.h>

int main(int argc, char **argv){
	// Create planet
	Planet* planet = newPlanet("Mars");
	// add metadata of planet
	planet->windSpeeds = 32;
	planet->relativeGravity = 0.375;
	planet->temperature = -60;
	planet->distanceFromEarth = 349.67;
	planet->orbitingSpeed = 23.47;
	planet->axisTilt = 25;
	planet->atmosphereDepth = 10.8;
	//print initial information
	printPlanet(planet);
	printf("\n");

	// Create rover
	Rover* rover = newRover("Perseverance");
	// print rover initial information
	printRover(rover);
	// Launch from earth into space
	launch(rover, planet);
	printf("\n");
	// Travel in space towards planet
	travel(rover, planet);
	printf("\n");

	// Land rover on the surface of the planet
	land(rover, planet);

	free(planet);
	free(rover);

	return 0;
}