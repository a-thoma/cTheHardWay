#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	if (argc != 2) {
		printf("ERROR: You need one argument.\n");

		// return the code for aborting a program (any non-zero)
		return 1;
	}

	/*******************************************************************
	 * We don't have to initialize the i or letter variables before we
	 * actually use them. We can declare them within the for loop. Also,
	 * We can initialize letter as an int, and set it to 0, because all
	 * ASCII letters can be modified using any (hexa)decimal arithmetic.
	 */
	for (int i = 0, letter = 0; argv[1][i] != '\0'; i++) {

		// Grab a letter from the argv
		letter = argv[1][i];

		// Check if our letter is lowercase
		if (letter < 97) {

			// If not, then convert it
			letter += 32;
		}

		switch(letter) { // eliminated fall-throughs
			case 'a':

				printf("%d: 'A'\n", i);
				break;
			case 'e':

				printf ("%d: 'E'\n", i);
				break;
			case 'i':

				printf("%d: 'I'\n", i);
				break;
			case 'o':

				printf("%d: 'O'\n", i);
				break;
			case 'u':

				printf("%d: 'U'\n", i);
				break;
			case 'y':
				if (i > 2) {

					// it's only sometimes Y, right? Haha funny maymay lelelele
					printf("%d: 'Y'\n", i);
				}
				break;

			default:
			
				printf("%d: %c is not a vowel\n", i, letter);
		}
	}

	return 0;
}