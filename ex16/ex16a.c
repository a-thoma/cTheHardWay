#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	/* initialize array of ages (int) and names (char) */
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	/* pointer declaration */
	int *cur_age = ages;
	char **cur_name = names;

	/* grab the size of ages
	 * divide size of ages array (in int's byte-size) by size of int
	/*/
	int count = sizeof(ages) / sizeof(int);

	/* declare iterator for a for loop outside the logic */
	int i = 0;

	/* reworked for pointers only, backwards*/
	for (i = count - 1; i >= 0; i--) {

		/* print some stuff using the names and ages arrays */
	 	printf("%s has %d years alive.\n", *(cur_name + i), *(cur_age + i));
	}

	/* separator */
	printf("---\n");

	/* reworked for pointers only, backwards */
	for (i = count - 1; i >= 0; i--) {

	  	/* print the stuff */
		printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
	}

	/* separator */
	printf("---\n");

	/* reworked for pointers only, backwards */
	for (i = count - 1; i >= 0; i--) {

	  	/* print more stuff */
	  	printf("%s is %d years old again.\n", *(cur_name + i),
	  										  *(cur_age + i));
	}

	/* separator */
	printf("---\n");

	/* reworked for pointers only, backwards */
	for (cur_name = (names + count - 1), cur_age = (ages + count - 1);
													(cur_age) >= ages;
													cur_name--, cur_age--) {

	  	/* print more of the stuff */
	  	printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	/* we're done here */
	return 0;
}