#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void swap(int *arr, int i, int j); /* could return 0 for good swap/else 1 */
int partition(int *arr, int lo, int hi);
void quicksort(int *arr, int lo, int hi);
void quicksort_helper(int *arr, int length);

#endif