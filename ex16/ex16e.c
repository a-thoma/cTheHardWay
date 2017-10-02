#include <stdio.h>

void printArray(int count, int ages[], char *names[]) {

	int i = 0;
	for (i = 0; i < count; i++) {

		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	/* we're done here, print a separator */
	printf("---\n");
}

void printPointerArithmetic(int count, int *age_ptr, char **char_ptr) {

	/* print out our arguments via function call */
	int i = 0;
	for (i = 0; i < count; i++) {

		printf("%s is %d years old.\n",  *(char_ptr + i), *(age_ptr + i));
	}

	/* we're done here, print a separator */
	printf("---\n");
}

void printArrayPointer(int count, int *age_ptr, char **char_ptr) {

	int i = 0;
	for (i = 0; i < count; i++) {

		printf("%s is %d years old again.\n", char_ptr[i], age_ptr[i]);
	}

	/* we're done here, print a separator */
	printf("---\n");
}

void printPointerForArithmetic(int count, int *age_ptr, char **char_ptr) {

	int i = 0;
	for (i = 0; i < count; age_ptr++, char_ptr++, i++) {

		printf("%s lived %d years so far.\n", *char_ptr, *age_ptr);
	}

	/* we're done here, print a separator */
	printf("---\n");
}

int main(int argc, char *argv[]) {
	
	/* initial arrays */
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	int count = sizeof(ages) / sizeof(int);

	/* pointers to arrays */
	int *ages_ptr = ages;
	char **name_ptr = names;
	
	/* call the print functions */
	printArray(count, ages, names);
	printPointerArithmetic(count, ages_ptr, name_ptr);
	printArrayPointer(count, ages_ptr, name_ptr);
	printPointerForArithmetic(count, ages_ptr, name_ptr);

	/* we're done here */
	return 0;
}