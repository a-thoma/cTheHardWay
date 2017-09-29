#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	/* initialize array of ages (int) and names (char) */
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	/* grab the size of ages
	 * divide size of ages array (in int's byte-size) by size of int
	/*/
	int count = sizeof(ages) / sizeof(int);

	/* declare iterator for a for loop outside the logic */
	int i = 0;

	/* for loop */
	/* reworked for going backwards through the arrays/pointer addresses */
	for (i = count - 1; i >= 0; i--) {

		/* print some stuff using the names and ages arrays */
	 	printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	/* separator */
	printf("---\n");

	/* setup a pointer to the ages array, and a pointer to the char array
	 * ages is 1d, so we need to dereference its pointer once, but the
	 * names array is 2d (*names[]) so it needs to be dereferenced twice
	 *                    ^     ^^
	/*/
	int *cur_age = ages;
	char **cur_name = names;

	/* use pointer arithmetic to print some stuff like above using i again */
	/* reworked for going backwards through the arrays/pointer addresses */
	for (i = count - 1; i >= 0; i--) {

	  	/* print the stuff */
		printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));
	}

	/* separator */
	printf("---\n");

	/* use pointers as arrays to print stuff like the first one */
	/* reworked for going backwards through the arrays/pointer addresses */
	for (i = count - 1; i >= 0; i--) {

	  	/* print more stuff */
	  	printf("%s is %d years old again.\n", cur_name[i],
	  										  cur_age[i]);
	}

	/* separator */
	printf("---\n");

	/* use pointers a ridiculous way 
	 * resets the pointers for part of for loop logic stmt,
	 * boundary of the address of ages minus ages being less than count,
	 * essentially making sure we don't go past the number of items
	 * increment through our arrays and print their values using pointers
	/*/
	/* reworked for going backwards through the arrays/pointer addresses */
	for (cur_name = (names + count - 1), cur_age = (ages + count - 1);
													(cur_age) >= ages;
													cur_name--, cur_age--) {

	  	/* print more of the stuff */
	  	printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	/* separator */
	printf("---\n");

	/* print the addresses the pointers are using */
	for (i = 0; i < count; i++) {
		
		/* print the stuff... again... */
		printf("Address of element %d:\n\t cur_name: %p \n\t cur_age: %p\n",
			i, (cur_name + i), (cur_age + i));
	}

	/* we're done here */
	return 0;
}