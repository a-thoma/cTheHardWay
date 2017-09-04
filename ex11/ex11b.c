#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	if (argc != 2) {
		printf("ERROR: You need one argument.\n");

		// return the code for aborting a program (any non-zero)
		return 1;
	}

	for (int i = 0, letter = 0; argv[1][i] != '\0'; i++) {

		// Grab a letter from the argv
		letter = argv[1][i];

		// Check if our letter is lowercase
		if (letter < 97) {

			// If not, then convert it
			letter += 32;
		}

		// Now we use an if-statement instead of a switch-case statement

		if(letter == 'a')        {

			printf("%d: 'A'\n", i);

		} else if(letter == 'e') {

			printf("%d: 'E'\n", i);

		} else if(letter == 'i') {

			printf("%d: 'I'\n", i);

		} else if(letter == 'o') {

			printf("%d: 'O'\n", i);

		} else if(letter == 'u') {

			printf("%d: 'U'\n", i);

		} else if(letter == 'y') {

			if(i > 2) {

				printf("%d: 'Y'\n", i);
			}
		} else {

			printf("%d: %c is not a vowel.\n", i, letter);
		}
	}

	return 0;
}