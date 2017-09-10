#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	int numbers[4] = { 0 };
	char name[4] = { 'a' }; // (less common)

	// print out the values raw
	printf("numbers: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
		name[0], name[1],
		name[2], name[3]);

	printf("name: %s\n", name);

	// setup the numbers
	numbers[0] = 1;
	numbers [1] = 2;
	numbers [2] = 3;
	numbers [3] = 4;

	//set up the name (manually)
	name[0] = 'A';
	name[1] = 'l';
	name[2] = 'x';
	name[3] = '\0'; // Somehow changing this to 'A' doesn't break it.

	// then print out the newly-initialized values
	printf("numbers: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
		name[0], name[1],
		name[2], name[3]);

	printf("name: %s\n", name);

	//another way to declare string literals (more common)
	char *another = "Alex";

	printf("another: %s\n", another);

	printf("another each: %c %c %c %c\n",
		another[0], another[1],
		another[2], another[3]);

	/*
	* Treating the char array '"name" like an integer requires you to
	* dereference it when you print it out as an integer (using %i).
	* This tells the printf function to look for the full size of name, and
	* handle its value as a number rather than a char.
	*/

	printf("name as an integer: %i\n", *name);

	return 0;
}