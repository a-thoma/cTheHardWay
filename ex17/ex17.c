#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* front declarations */
struct Person *Person_create(char *name, int age, int height, int weight);
void Person_destroy(struct Person *who);
void Person_print(struct Person *who);

/* define struct Person */
struct Person {

	/* elements of a Person */
	char *name;
	int age;
	int height;
	int weight;
};

/* constructor for struct Person
 * called when new Person is made
/*/
struct Person *Person_create(char *name, int age, int height, int weight) {

	/* use malloc() to allocate memory of size Person
	 * malloc() will do the calculations based on the argument passed to it,
	 * in this case, sizeof(struct Person) to determine the right amount of 
	 * memory to use
	/*/
	struct Person *who = malloc(sizeof(struct Person));

	/* make sure malloc() did what it's supposed to do, otherwise
	 * assert will print some info to stderr and send SIGABT (abort())
	/*/
	assert(who != NULL);

	/* bring in the values passed to Person_create
	 * and set the elements of our Person 
	/*/
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	/* exit and return the new Person */
	return who;
}

/* destructor for struct Person
 * called at the end of main or any function that creates a new Person
 * to free the memory used at the end and exit without any memory left
 * allocated
/*/
void Person_destroy(struct Person *who) {

	/* make sure our Person exists */
	assert(who != NULL);

	/* call free() on any pointers made
	 * this would include the char *name within our Person, and the Person
	 * itself
	/*/
	free(who->name);
	free(who);

	/* we're done here */
}

/* function to print some info about a Person */
void Person_print(struct Person *who) {

	/* print some info */
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);

	/* we're done here */
}

/* main driver function */
int main(int argc, int *argv[]) {
	
	/* make two Persons */
	struct Person *joe = Person_create(
		"Joe Blow", 32, 64, 140);

	struct Person *frank = Person_create(
		"Frank Blank", 20, 72, 180);

	/* print out our Persons and their locations in memory */
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	/* change some elements of our Persons and print them again */
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight+= 20;
	Person_print(frank);

	/* DESTROY ALL PERSONS */
	Person_destroy(joe);
	Person_destroy(frank);

	/* we're done here */
	return 0;
}