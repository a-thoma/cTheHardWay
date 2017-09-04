#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	int i = 0; // Do we need this initialized if we change it below...?

	// Go through each string in argv (the argument vector)
	// Skipping argv[0] because that's the initial program call from the shell.
	for (i = 1; i < argc; i++) {

		printf("arg %d: %s\n", i, argv[i]);
	}

	// Make an array of strings
	char *states[] = {"California", "Oregon", "Washington", "Texas" };

	int num_states = 4;

	for (i = 0; i < num_states; i++) {

		printf("State %d: %s\n", i, states[i]);
	}
	
	return 0;
}