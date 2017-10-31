/*
 *	This is the Lomuto partition scheme for quicksort popularized by the
 *	"Programming Pearls" book
 *
 *	please refer to the appropriate section in that book to learn about
 *	this algorithm implementation
 */

#include <stdio.h>
#include <stdlib.h>

/* prototypes */
void swap(int *arr, int i, int j); /* could return 0 for good swap/else 1 */
int partition(int *arr, int lo, int hi);
void quicksort(int *arr, int lo, int hi);
void quicksort_helper(int *arr, int length);

/* functions/procedures */


/************** swapping procedure ***************
 * swaps two elements, i and j, in the array arr *
 *************************************************
 */
void swap(int *arr, int i, int j) {

	/* local variables */
	int temp = arr[i]; /* our temporary storage */

	/* swap the variables around */
	arr[i] = arr[j];
	arr[j] = temp;

	/* we're done here */
}

/************ partition function *************
 * returns the partition index for our array *
 *********************************************
 */
int partition(int *arr, int lo, int hi) {

	/* local variables */
	int pivot = arr[hi]; /* our pivot value from the array */

	/* IMPLEMENT THIS */
}

/********************** quicksort main procedure **********************
 * given an array of arbitrary size, sorts the array according to the *
 * quicksort algorithm:                                               *
 *                              * * *                                 *
 * EXPLAIN HERE(?)                                                    *
 **********************************************************************
 */
void quicksort(int *arr, int lo, int hi) {

	/* local variables */

	/* check if our lo index is less than our hi index */
	if(lo < hi) {

		/* grab partition index of the array */
		int p = partition(arr, lo, hi);

		/* recursively call quicksort on two new partitions of the array */
		quicksort(arr, lo, (p - 1));
		quicksort(arr, (p + 1), hi);
	}

	/* we're done here */
}

/* ********************* quicksort helper procedure **********************
 * calculates the lo and hi value from the passed arguments, which are   *
 * the array and its length, respectively                                *
 *                                                                       *
 * calls the quicksort main procedure on the array and its initial lo/hi *
 *************************************************************************
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

	/* local variables */
	int i = 0; 						/* iterator */
	int arr[] = {2, 6, 3, 1, 5, 4}; /* array to sort */
	int length = (sizeof(arr) / sizeof(int));

	/* get a pointer for our array */
	int *arrptr = arr;

	/* sort the array via quicksort */
	quicksort_helper(arrptr, length);

	/* print out the array again */
	for (i = 0; i < length; i++) {

		/* print an element from the array with some pretty formatting */
		printf("Element %d: %d\n", i, arr[i]);
	}

	/* we're done, and nothing went wrong */
	return EXIT_SUCCESS;
}