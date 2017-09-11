#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
int can_print_it(char ch);
void print_letters(int len, const char arg[]);
void print_arguments(int argc, const char *argv[]);

/*
 * Method that takes the arguments for main, cycles through the argv
 * using argc, and calls print_letters() on each letter. This version 
 * specifically calculates the length of the argument using strlen(),
 * and then passes the length along with the argument to print_letters().
 */
void print_arguments(int argc, const char *argv[]) {

	// TODO: EC 2
	int i = 0;
	for(i = 0; i < argc; i++) {

		int len = strlen(argv[i]);
		print_letters(len, argv[i]);
	}
}

/*
 * method that thakes in a const char array,of 1-d, cycles through the letters
 * in the char array, and calls can_print_it() on each char. If can_print_it()
 * returns with 1, prints the chars from the array. If the method can_print_it()
 * returns 0, the chars are not printed.
 */
void print_letters(int len, const char arg[]) {
	
	int i = 0;

	for(i = 0; i < len; i++) {

		char ch = arg[i];

		if (can_print_it(ch)) {

			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

/*
 * method that takes in a char as its argument, and calls two functions
 * from ctype.h, called isalpha() and isblank(). If isalpha() returns true,
 * the char entered is of the alphabet (A-Z, a-z). If isblank() is true, then
 * the char entered is a tab or a space.
 */
int can_print_it(char ch) {
	
	return isalpha(ch) || isblank(ch);
}

/*
 * Main driver function.
 */
int main(int argc, const char *argv[]) {
	
	print_arguments(argc, argv);

	return 0;
}