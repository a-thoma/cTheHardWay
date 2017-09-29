#include <stdio.h>

int main(int argc, char *argv[]) {
	
	/* process arguments from the argv a la ex16 */

	/* iterator */
	int i;

	for (i = 0; i < argc; i++) {

		/* print the arguments */
		printf("Argument #%d: %s\n", i, argv[i]);
	} 

	/* separator */
	printf("---\n");

	/* pointer arithmetic */

	int *argc_ptr = &argc; /* this is dumb & useless/redundant */
	char **argv_ptr = argv;

	for(i = 0; i < *argc_ptr; i++) {

		/* print the arguments again */
		printf("Argument #%d: %s\n", i, *(argv_ptr + i));
	}

	/* separator */
	printf("---\n");

	/* arrays again using pointers */
	for (i = 0; i < argc; i++) {

		/* print the arguments thrice */
		printf("Argument #%d: %s\n", i, argv_ptr[i]);
	}

	/* separator */
	printf("---\n");

	/* pointers by incrementation within for loop */
	/* THIS WILL ACTUALLY flow over into your environment variables
	 * and print those out after your arguments, because it's not
	 * incrementing the iterator i, but only the argv pointer...
	 */
	for (i = 0, argv_ptr = argv;
		i < *argc_ptr;
		argv_ptr++) { /* note the lack of "i++" here */

		/* print the arguments a total of four times */
		printf("Argument #%d: %s\n", i, *argv_ptr);
	}

	/* we're done here */
	return 0;
}