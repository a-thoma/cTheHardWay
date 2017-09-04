#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	// NO BOOLEANS, ONLY INTEGERS OF VALUE 1/0
	// REAL C HOURS ONLY

	int i = 0;

	if(argc == 2) {

		printf("You only have one argument: %s. You suck.\n", argv[1]);
	} else if(argc > 1 && argc < 4) {
		/*************************************************************
		* The fun thing about this if statement's logic is if you
		* change the and (&&) to an or (||) it takes as many arguments
		* as you can fit into it, and those satisfy this else case.
		*/

		printf("Here's your arguments:\n");

		for (i = 0; i < argc; i++) {

			printf("%s ", argv[i]);
		}

		printf("\n");
	} else {

		printf("You have too many/few arguments. You suck.\n");
	}

	return 0;
}