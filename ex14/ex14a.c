#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	int i = 0;
	while(i < argc) {

		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	// another array of strings...
	char *states[] = {

		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;
	i = 0; // this is important?
	while(i < num_states) {

		printf("state %d: %s\n", i, states[i]);
		i++;
	}

	return 0;
}