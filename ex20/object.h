/* object header file */

/* if _OBJECT_H is not already defined */
#ifndef _OBJECT_H

/* define _OBJECT_H */
#define _OBJECT_H

/* enumeration of four cardinal directions called Direction */
typedef enum {
	
	NORTH, SOUTH, EAST, WEST
} Direction;

/* struct for Object */
typedef struct {
	
	/* elements of Object */
	char *description;

	/* functions inherent to struct Object */
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move) (void *self, Direction direction);
	int (*attack) (void *self, int damage);
} Object;

/* prototypes */
int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

/* c preprocessor definitions */

/* define a macro, NEW(T,N) for calling Object_new
 * T###Proto means to concatenate Proto at the end of variable T
 */
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)

/* macro "syntactic sugar" that replaces obj->proto.blah with obj->_(blah) */
#define _(N) proto.N

/* we're done */
#endif