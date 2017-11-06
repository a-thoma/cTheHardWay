/* object source file */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* our own header */
#include "object.h"

/* functions */
void Object_destroy(void *self) {
	
	/* grab our object */
	Object *obj = self;

	/* if the object exists, free it from memory */
	if(obj) {

		/* if there's a description, free it from memory */
		if(obj->description) free(obj->description);
		free(obj);
	}
}

void Object_describe(void *self) {
	
	/* grab our object */
	Object *obj = self;

	/* print the description */
	printf("%s.\n", obj->description);
}

int Object_init(void *self) {
	
	/* does nothing */
	return 1;
}

void *Object_move(void *self, Direction direction) {
	
	/* can't go there */
	printf("You can't go that direction.\n");
}

int Object_attack(void *self, Direction direction) {
	
	/* I'm sorry dave, */
	printf("You can't attack that.\n");

	/* we're done here */
	return 0;
}

void *Object_new(size_t size, Object proto, char *description) {
	
	/* setup the default functions in case they aren't set */
	if(!proto.init) proto.init = object_init;
	if(!proto.describe) proto.describe = Object_describe;
	if(!proto.destroy) proto.destroy = Object_destroy;
	if(!proto.attack) proto.attack = Object_attack;
	if(!proto.move) proto.move = Object_move;

	/* cast our Object in a weird way */
	Object *el = calloc(1, size);
	*el = proto;

	/* copy the Object's description */
	el->description = strdup(description);

	/* init the object with whatever we had */
	if(!el->init(el)) {

		/* if we're here, then it didn't initialize properly */
		el->destroy(el);
		return NULL;
	} else {

		/* we're done here, return the object created */
		return el;
	}
}