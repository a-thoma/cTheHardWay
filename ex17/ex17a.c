#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* front declarations */
void Person_print(struct Person who);

/* define our struct */
struct Person {

	/* elements of our struct */
	char *name;
	int age;
	int height;
	int weight;
};

/* function to print some info about a Person */
void Person_print(struct Person who) {

	/* print some info */
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);

	/* we're done here */
}

/* main driver function */
int main(int argc, char *argv[]) {
	
	/* declare our Person on the stack */
	struct Person joe;
	struct Person frank;

	/* assign elements */

	/* joe */
	joe.name = "Joe Blow";
	joe.age = 32;
	joe.height = 64;
	joe.weight = 140;

	/* frank */
	frank.name = "Frank Blank";
	frank.age = 20;
	frank.height = 72;
	frank.weight = 180;

	/* print some stuff about them */

	printf("%s is at memory location %p\n", joe.name, joe);
	Person_print(joe);

	printf("%s is at memory location %p\n", frank.name, frank);
	Person_print(frank);

	/* modify our Persons */
	joe.age += 20;
	joe.height -= 2;
	joe.weight += 40;
	Person_print(joe);

	frank.age += 20;
	frank.weight+= 20;
	Person_print(frank);

	/* we're done here */
	return 0;
}