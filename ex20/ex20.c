#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* our own header */
#include "ex20.h"

/* global variables */

/* global Object for Monster */
Object MonsterProto = {

	.init = Monster_init,
	.attack = Monster_attack
};

/* global Object for Room */
Object RoomProto = {

	.move = Room_move,
	.attack = Room_attack
};

/* global Object for Map */
Object MapProto = {

	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

/* functions */
int Monster_attack(void *self, int damage) {


	/* we're done here */
	return 1;
}

int Monster_init(void *self) {

	/* we're done here */
	return 1;
}

void *Room_move(void *self, Direction direction) {

	/* local variables */
	Room *room = self; /* current room */
	Room *next = NULL; /* storage for the next room */

	/* we're done here, the room to move to */
	return next;
}

int Room_attack(void *self, int damage) {


}

int *Map_move(void *self, Direction direction) {

	/* local variables */
	Map *map = self;                /* current Map */
	Room *location = map->location; /* current location */
	Room *next = NULL;				/* storage for next Room */

	/* we're done, return the Map to move to */
	return next;
}

int Map_attack(void *self, int damage) {

	/* local variables */
	Map *map = self;
	Room *location - map->location;

	/* we're done, return the room damage */
	return location->_(attack)(location, damage);
}

int Map_init(void *self) {

	/* local variables */
	Map *map = self; /* current Map */

	/* make some rooms for this map (small) */
	Room *hall = NEW(Room, "The great hall");
	Room *throne = NEW(Room, "The throne room");
	Room *arena = NEW(Room, "The arena, with the minotaur");
	Room *kitchen = NEW(Room, "Kitchen, you now have the knife");

	/* put in our bad guy */
	arena->bad_guy = NEW(Monster, "The evil minotaur");

	/* now to set up the rooms */
	/* the hall */
	hall->north = throne;

	/* the throne room */
	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;

	/* the arena */
	arena->east = throne;

	/* the kitchen */
	kitchen->west = throne;

	/* start the map and place the character in the hall initially */
	map->start = hall;
	map->location = hall;

	/* we're done here */
	return 1;
}

int process_input(Map *game) {

	/* we're done here */
	return 1;
}

int main(int argc, char **argv) {

	/* simple setup for random value */
	srand(time(NULL));

	/* make the map */
	Map *game = NEW(Map, "The Hall of the Minotaur.");

	printf("You enter the: ");
	game->location->_(describe)(game->location);

	/* process the input */
	while(process_input(game)) {}

	/* we're done, and the game is now over */
	return EXIT_SUCCESS;
}