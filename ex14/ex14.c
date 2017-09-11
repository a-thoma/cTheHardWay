#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	int i = 0;

	for (i = 1; i < argc; i++) {

		printf("arg %d: %s\n", i, argv[i]);
	}

	// make our own array of strings

	/*
	* Because we're declaring it as a pointer (*) AND using brackets
	* to denote an array ([]) we have created a 2-dimensional array,
	* where the words are the first dimension, and each letter of each
	* word is the second dimension.
	*/
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;

	for (i = 0; i < num_states; i++) {

		printf("State %d: %s\n",i , states[i]);
	}

	return 0;
}