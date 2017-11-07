/* ex20 header file */

#ifndef _EX20_H
#define _EX20_H

#include "object.h"

/* struct Monster, with alias */
typedef struct Monster {
	
	/* elements of struct Monster */
	Object proto;
	int hit_points;
} Monster;

/* prototypes for struct Monster */
int Monster_attack(void *self, int damage);
int Monster_init(void *self);

/* struct Room, with alias */
typedef struct Room {

	/* elements of struct Room */
	Object proto;

	Monster *bad_guy;

	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
} Room;

/* prototypes for struct Room */
void *Room_move(void *self, Direction direction);
int Room_attack(void *self, int damage);
int Room_init(void *self);

/* struct Map, with alias */
typedef struct Map {

	/* elements of sttruct Map */
	Object proto;
	Room *start;
	Room *location;
} Map;

/* prototypes for struct Map */

void *Map_move(void *self, Direction direction);
int Map_attack(void *self, int damage);
int Map_init(void *self);

/* we're done here */
#endif