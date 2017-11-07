/* TODO:
 *	assert checks for everything (check book 20.5 Auditing)
 *
 * EXTRA CREDIT
 *	ec 1 (done)
 *	write make test that calls for a textfile of commands as a script for game
 *	testing make another map/add to current make with more rooms/monsters
 *	place the game mechanics into a third file, compile it to an outfile .o,
 *	and use that to write another game if you want
 *	you should only have to write your own Map and main in the game (basically
 *	separate the attack/move/etc functions into their own c file)
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/* our own header */
#include "ex20.h"

/* global variables */

/* global Object prototype for Monster */
Object MonsterProto = {

	.init = Monster_init,
	.attack = Monster_attack
};

/* global Object prototype for Room */
Object RoomProto = {

	.move = Room_move,
	.attack = Room_attack
};

/* global Object prototype for Map */
Object MapProto = {

	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

/* functions */
int Monster_attack(void *self, int damage) {

	/* grab our Monster */
	Monster *monster = self;

	/* print the action */
	printf("You attack %s!\n", monster->_(description));

	/* adjust the Monster's hp as needed */
	monster->hit_points -= damage;

	/* if the monster has hp>0, it's alive, otherwise it's dead */
	if(monster->hit_points > 0) {

		printf("It is still alive.\n");

		/* it's alive! */
		return 0;
	} else {

		printf("It is dead!\n");

		/* he's dead, jim */
		return 1;
	}

	/* we're done here */
	return 1;
}

int Monster_init(void *self) {

	/* grab our Monster */
	Monster *monster = self;

	/* set the monster's base hp */
	monster->hit_points = 10;

	/* we're done here */
	return 1;
}

void *Room_move(void *self, Direction direction) {

	/* local variables */
	Room *room = self; /* current room */
	Room *next = NULL; /* storage for the next room */

	/* logic for maneuvering the room(s)
	 * basically, if the room exists in the direction you're moving,
	 * you go there, otherwise you can't go there
	 */
	if(direction == NORTH && room->north) {

		printf("You go north, into:\n");
		next = room->north;
	} else if(direction == SOUTH && room->south) {

		printf("You go south, into:\n");
		next = room->south;
	} else if(direction == EAST && room->east) {

		printf("You go east, into:\n");
		next = room->east;
	} else if(direction == WEST && room->west) {

		printf("You go west, into:\n");
		next = room->west;
	} else {

		printf("You can't go that direction.");
		/* is there really a need to set next NULL when it's already null? */
	}

	if(next) {

		next->_(describe)(next);
	}

	/* we're done here, the room moved to */
	return next;
}

int Room_attack(void *self, int damage) {

	/* grab our Room */
	Room *room = self;

	/* grab the Monster in the Room */
	Monster *monster = room->bad_guy;

	/* if the monster exists, then we've attacked it
	 * otherwise, we swung blindly into the air
	 */
	 if(monster) {

	 	monster->_(attack)(monster, damage);

	 	/* we attacked something */
	 	return 1;
	 } else {

	 	printf("You flail in the air at nothing. Idiot.\n");

	 	/* we were an idiot */
	 	return 0;
	 }
}

void *Map_move(void *self, Direction direction) {

	/* local variables */
	Map *map = self;                /* current Map */
	Room *location = map->location; /* current location */
	Room *next = NULL;				/* storage for next Room */

	/* set the next location */
	next = location->_(move)(location, direction);

	/* if next exists, then set the Map location to that next */
	if(next) {

		map->location = next;
	}

	/* we're done, return the Map to move to */
	return next;
}

int Map_attack(void *self, int damage) {

	/* local variables */
	Map *map = self;
	Room *location = map->location;

	/* we're done, attack and return the room damage */
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

	/* print a new line and a single chevron,the decided input prompt */
	printf("\n> ");

	/* get the action */
	char ch = getchar();
	getchar(); /* we don't need the enter passed in, so eat it and forget it */

	/* calculate the damage - randomly */
	int damage = rand() % 4;

	/* switch-case for our input */
	switch(ch) {

		/* quit */
		case -1: /* fallthrough to quit case */
		case 'q':
			printf("Giving up? You suck.\n");
			return 0;
			break;

		/* directional */
		case 'n':
			game->_(move)(game, NORTH);
			break;
		case 's':
			game->_(move)(game, SOUTH);
			break;
		case 'e':
			game->_(move)(game, EAST);
			break;
		case 'w':
			game->_(move)(game, WEST);
			break;

		/* attack */
		case 'a':
			game->_(attack)(game, damage);
			break;

		/* look around */
		case 'l':
			printf("You can go:\n");
			if(game->location->north) printf("NORTH\n");
			if(game->location->south) printf("SOUTH\n");
			if(game->location->east) printf("EAST\n");
			if(game->location->west) printf("WEST\n");
			break;

		/* default */
		default:
			printf("What? (unrecognized character: %d)\n", ch);
	}

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