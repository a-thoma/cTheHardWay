#include <stdio.h>

int main (int argc, const char *argv[]) {
	
	int areas[] = {10, 12, 13, 14, 20};

	// char array declared as one single string
	char name[] = "Alex";

	// char array declared one by one, as each indiividual char
	// notice the null-character at the end, making a NTS
	char full_name[] = {
		'A', 'l', 'e', 'x', 'a', 'n', 'd', 'e', 'r', ' ',
		'C', '.', ' ',
		'T', 'h', 'o', 'm', 'a', 's', 'o', 'n', '\0'
	};

	// WARNING: this might need to change %ld to a %u, as sizeof is unsigned

	/*
	 * Recall that ints are 4 bytes (32-bit) by default, and that chars are
	 * 1 byte (8 bits) by default. Size of will give size measured in bytes.
	 */

	printf("The size of an int: %ld\n", sizeof(int));

	printf("The size of areas (int[]): %ld\n", sizeof(areas));

	printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));

	printf("The first area is %d, the second area is %d\n", areas[0], areas[1]);

	printf("The size of a char: %ld\n", sizeof(char));

	printf("The size of name (char[]): %ld\n", sizeof(name));

	printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));

	printf("The size of full_name (char[]): %ld\n", sizeof(full_name));

	printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

	printf("name = \"%s\" and full_name = \"%s\"\n", name, full_name);

	return 0;
}