/*
 *	RECURSIVE QUICKSORT
 *
 *	This implementation of quicksort utilizes the first element of any
 *	partition as the pivot value.
 *
 */

 /* TODO: Fix edge case with array (TODO tags in main) */

#include <stdio.h>
#include <stdlib.h>

/* prototypes */
void swap(int *arr, int i, int j); /* could return 0 for good swap/else 1 */
int partition(int *arr, int lo, int hi);
void quicksort(int *arr, int lo, int hi);
void quicksort_helper(int *arr, int length);

/* functions/procedures */

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
 * given an array of arbitrary size, sorts the array according to the
 * quicksort algorithm:
 *
 * EXPLAIN HERE(?)
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
 * quicksort helper procedure
 *
 * calculates the lo and hi value from the passed arguments, which are
 * the array and its length, respectively
 *
 * calls the quicksort main procedure on the array and its initial lo/hi
 */
void quicksort_helper(int *arr, int length) {

	/* local variables */
	int lo = 0;								/* initial lo element */
	int hi = (length - 1);					/* initial hi element */

	/* call quicksort */
	quicksort(arr, lo, hi);
}

/* main driver function */
int main(int argc, char **argv) {

	/* test the functionality of our quicksort on a small sample array */

	/* local variables */
	int i = 0; 						/* iterator */

	int arr[] = {1, 6, 3, 2, 5, 4}; /* array to sort */
	int length = (sizeof(arr) / sizeof(int));

	/* get a pointer for our array */
	int *arrptr = arr;

	/* print array before quicksort */
	printf("UNSORTED:\n");

	for (i = 0; i < length; i++) {

		/* print an element from the array with some pretty formatting */
		printf("Element %d: %d\n", i, arr[i]);
	}

	/* sort the array via quicksort */
	quicksort_helper(arrptr, length);

	printf("SORTED:\n");
	/* print out the array again */
	for (i = 0; i < length; i++) {

		/* print an element from the array with some pretty formatting */
		printf("Element %d: %d\n", i, arr[i]);
	}

	/* we're done, and nothing went wrong */
	return EXIT_SUCCESS;
}