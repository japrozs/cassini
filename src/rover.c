#include <stdio.h>
#include <cassini.h>
#include <unistd.h>
#include <stdlib.h>
#include <rover.h>

Rover* newRover(char* name){
	Rover* rover = malloc(sizeof(Rover));
	if(rover == NULL){
		printf("🛑 Couldn't allocate memory for a new planet\n");
		exit(1);
	}
	rover->name = name;
	rover->parachutesDeployed = false;
	rover->thrustersOn = false;
	rover->landed = false;
	rover->timeTaken = 0.0;

	return rover;
}

void launch(Rover* rover, Planet* planet){
	double launchTime = (planet->distanceFromEarth * 100000)/ SPEED;
	printf("Systems ready!\n");
	printf("Ready for launch!\n");
	printf("We have liftoff!\n");
	for ( int loop = 0; loop < 2; ++loop) {
        for ( int each = 0; each < 4; ++each) {
            printf ("\rLaunching %s towards %s %.*s   \b\b\b",rover->name, planet->name ,each, "...");
            fflush (stdout);//force printing as no newline in output
            sleep (1);
        }
    }
    printf ( "\tDone\n");
    rover->timeTaken = rover->timeTaken + launchTime;
    printf("Launch took %fs\n", launchTime);
}

void travel(Rover* rover, Planet* planet){
	for ( int loop = 0; loop < 2; ++loop) {
        for ( int each = 0; each < 4; ++each) {
            printf ("\rTravelling in space towards %s %.*s   \b\b\b",planet->name ,each, "...");
            fflush (stdout);//force printing as no newline in output
            sleep (1);
        }
    }
    printf ( "\tDone\n");
    printf("Successfully reached planet %s\n", planet->name);
}

void printRover(Rover* rover){
	printf(
		"========= Rover information =========\n\n"
		"  Name                :: %s\n"
		"  Parachutes Deployed :: %s\n"
		"  Thrusters on        :: %s\n"
		"  Landed              :: %s\n"
		"  Time Taken          :: %fs\n\n"
		"=====================================\n",
		rover->name, rover->parachutesDeployed ? "true" : "false", rover->thrustersOn ? "true" : "false",
		rover->landed ? "true" : "false", rover->timeTaken
	);
}

void land(Rover* rover, Planet* planet){
	double travelTime = (planet->distanceFromEarth * 100000)/ SPEED;
	double entrySpeed = ((planet->distanceFromEarth * 1000)/ travelTime) + 1000;
	printf("Attempting to land on the surface of %s\n", planet->name);
	printf("Reached the atmosphere\n");
	printf("Entry Speed :: %fkm/h\n", entrySpeed);
	if(entrySpeed > 800){
		rover->parachutesDeployed = true;
		printf("Parachutes deployed!\n");
	}
	printf("Turning of the thrusters...\n");
	rover->thrustersOn = true;
	int i = rand() % 100 + 1;
	if(i > 10){
		printf("%s crashed on the surface due to an issues with the thruster!\n", rover->name);
		exit(1);
	}
	printf("Deplyoing rover...\n");
	printf("%s has successfully landed on the surface of %s\n", rover->name, planet->name);
}
