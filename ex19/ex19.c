#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

/* die function */
void die(const char *msg) {

	/* if there's an error */
	if(errno) {

		/* print the error message */
		perror(msg);
	} else {

		/* print a warning */
		printf("ERROR: %s\n", msg);
	}

	/* we're done here, exit indicating something went wrong */
	exit(1);
}

/* create an alias type for a function pointer */
typedef int (*compare_cb) (int a, int b);

/* textbook bubble sort algo as a function pointer */
int *bubble_sort(int *nums, int count, compare_cb cmp) {

	/* local variables */
	int temp = 0;
	int i, j = 0;
	int *target = malloc(count * sizeof(int));

	/* error checking for our target */
	if(!target) die("Memory error.");

	memcpy(target, nums, count * sizeof(int));

	/* double-nested for loops to implement bubblesort algo */
	for(i = 0; i < count; i++) {

		for(j = 0; j < count - 1; j++) {

			/* if the difference between two targets is greater than zero */
			if(cmp(target[j], target[j + 1]) > 0) {

				/* grab one of them */
				temp = target [j + 1];

				/* trade them around */
				target[j + 1] = target[j];
				target[j] = temp;
			}
		}
	}

	/* we're done here, return our now-sorted target */
	return target;
}

void quicksort(int *nums, int left, int right) {

	
}

/* helper function to handle quicksort
 * utilizes C built-in qsort function
 */
int *quick_sort_helper(int *nums, int count, compare_cb cmp) {
	int left = 0;
	int right = count - 1;
	int *target = malloc(count * sizeof(int));

	/* error checking */
	if(!target) die("Memory Error.");

	/* copy nums array to target array */
	memcpy(target, nums, count * sizeof(int));

	/* call quicksort on the array */
	quicksort(target, left, right);

	/* we're done here, return the sorted array */
	return target;

}



static inline int sorted_order(int a, int b) {

	return a - b;
}

static inline int reverse_order(int a, int b) {

	return b - a;
}

static int strange_order(int a, int b) {

	int result;

	if(a == 0 || b == 0) {

		result = 0;
	} else {

		result = a % b;
	}

	/* we're done here, return the result */
	return result;
}

void test_sorting(int *nums, int count, compare_cb cmp) {

	/* local variables */
	int i = 0;

	/* sort our array and return it */
	int *sorted = bubble_sort(nums, count, cmp);

	/* error checking on sort algo */
	if(!sorted) die("Failed to sort as requested.");

	/* print all of our elements */
	for(i = 0; i < count; i++) {

		/* print one */
		printf("%d ", sorted[i]);
	}

	/* print a new line */
	printf("\n");

	/* free our array */
	free(sorted);
}

int main(int argc, char **argv) {

	/* error checking for argc */
	if(argc < 2) die("USAGE: ./ex19 4 3 1 5 6");

	/* local variables */
	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	/* declare and allocate a new number array */
	int *numbers = malloc(count * sizeof(int));

	/* error checking on creation of number array */
	if(!numbers) die("Memory error.");

	/* grab inputs and place them into numbers */
	for(i = 0; i < count; i++) {

		numbers[i] = atoi(inputs[i]);
	}

	/* test the sorting */
	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	/* dealloc numbers */
	free(numbers);

	/* we're all done, return indicating everything went ok */
	return 0;
}