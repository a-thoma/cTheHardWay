/* TODO: Find out how to add cmp functionality to quicksort implementation */

/* TODO: Can I just make a header for quicksort and use that instead of
 * copying and pasting it in this source file?
 */

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

/*
 * swapping procedure
 * swaps two elements, i and j, in the array arr
 */
void swap(int *arr, int i, int j) {

	/* local variables */
	int temp = arr[i]; /* our temporary storage */

	/* swap the variables around */
	arr[i] = arr[j];
	arr[j] = temp;

	/* we're done here */
}

/*
 * partition function
 * returns the partition index for our array
 */
int partition(int *arr, int lo, int hi) {

	/* local variables */
	int i = lo + 1;     /* leftmost iterator */
	int j = hi; 	   /* rightmost iterator */
	int pivot = arr[lo]; /* pivot value */

	/* execute until we break out manually by midpoint break */
	while(1) {

		/* as long as our ith element is less than our pivot */
		while(arr[i] < pivot && i < hi) {

			/* iterate through the array */
			i++;
		}

		/* as long as our jth element is greater than our pivot */
		while(arr[j] > pivot && j > lo) {

			/* iterate through the array */
			j--;
		}

		/* if our iterators cross, we've gone too far */
		if(i >= j) break;

		/* swap our ith and jth elements */
		swap(arr, i, j);
	}

	/* swap our jth element with our pivot */
	swap(arr, lo, j);

	/* we're done here, return our pivot point */
	return j;
}

/* 
 * quicksort main procedure
 */
void quicksort(int *arr, int lo, int hi) {

	/* as long as our rightmost index isn't the first element */
	if(hi > 0) {

		/* get our partition element */
		int part = partition(arr, lo, hi);

		/* bounds checking for continuing quicksort left case */
		if(lo < (part - 1)) {

			/* recursive call to quicksort the left partition */
			quicksort(arr, lo, part - 1);
		}

		/* bounds checking for continuing quicksort right case */
		if((part + 1) < hi) {

			/* recursive call to quicksort the right partition */
			quicksort(arr, part + 1, hi);
		}
	}
	
	/* we're done here */
}

/*
 * helper function to handle quicksort
 *
 * sorts one way so far
 */
int* quick_sort_helper(int *nums, int count) {

	/* local variables */
	// int i = 0;
	int lo = 0;
	int hi = count - 1;
	int *target = malloc(count * sizeof(int));

	/* error checking */
	if(!target) die("Memory Error.");

	/* copy nums array to target array */
	memcpy(target, nums, count * sizeof(int));

	/* call quicksort on the array */
	quicksort(target, lo, hi);

	/* we're done here, print the array */
	// printf("SORTED BY QUICKSORT:\n");

	// for (i = 0; i < count; i++) {
		// printf("Element %d: %d\n", i, target[i]);
	// }

	/* return the array */
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

void test_sorting(int *nums, int count, compare_cb cmp, char *algo) {

	/* local variables */
	int i = 0;
	int *sorted;

	/* sort our array and return it according to algo chosen */
	if(!(strcmp(algo, "quicksort"))) {

		sorted = quick_sort_helper(nums, count);
	}

	if(!(strcmp(algo, "bubblesort"))) {

		sorted = bubble_sort(nums, count, cmp);
	}

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
	if(argc < 2) die("USAGE: ./ex19 <quicksort | bubblesort> <...numbers...>");

	/* local variables */
	char *algo = argv[1];
	int count = argc - 2;
	int i = 0;
	char **inputs = argv + 2;

	/* declare and allocate a new number array */
	int *numbers = malloc(count * sizeof(int));

	/* error checking on creation of number array */
	if(!numbers) die("Memory error.");

	/* grab inputs and place them into numbers */
	for(i = 0; i < count; i++) {

		numbers[i] = atoi(inputs[i]);
	}

	/* test the sorting */
	test_sorting(numbers, count, sorted_order, algo);
	test_sorting(numbers, count, reverse_order, algo);
	test_sorting(numbers, count, strange_order, algo);

	/* dealloc numbers */
	free(numbers);

	/* we're all done, return indicating everything went ok */
	return 0;
}