#include <stdio.h>

int main (int argc, const char *argv[]) {

	if (argc < 2) {

		printf("ERROR: No arguments.\n\n");
	}
	
	// Handle more than one word now
	for (int i = 1 ;i < argc; i++) {		

		// Print the word (for aesthetic cleanliness)
		printf("%s\n", argv[i]);

		for(int j = 0, letter = 0; argv[i][j]  != '\0'; j++) {

			// Grab our letter from argv
			letter = argv[i][j];

			// Convert letter to lowercase
			if(letter < 97) {

				letter += 32;
			}

			// Switch-case for letter
			switch(letter) {

				// Cases without fallthrough
				case 'a':

					printf("%d, %d: 'A'\n", i, j);
					break;

				case 'e':

					printf("%d, %d: 'E'\n", i, j);
					break;

				case 'i':

					printf("%d, %d: 'I'\n", i, j);
					break;

				case 'o':

					printf("%d, %d: 'O'\n", i, j);
					break;

				case 'u':

					printf("%d, %d: 'U'\n", i, j);
					break;

				case 'y':

					if(j > (sizeof(argv[i]) - 1) / 2) {

						printf("%d, %d: 'Y'\n", i, j);
					} else {

						printf("%d, %d: y is not a vowel... this time...\n", i, j);
					}
					break;

				default:

					printf("%d, %d: %c is not a vowel.\n", i, j, letter); 
			}
		}

		// Make a new line between the words
		printf("\n");
	}

	// We're done
	return 0;
}