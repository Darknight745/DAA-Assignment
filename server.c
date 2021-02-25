//Function definitions
#include "head.h"

long long count_sel = 0;
long long count_bubble = 0;
long long count_quick = 0;
long long count_merge = 0;

/*This function makes a copy of the given array*/
long *copyarr(long *src, long size) {
    long *dest = (long*)malloc(size * sizeof(long));
    memcpy(dest, src, size*sizeof(long));
    return dest;
}

/*This function return the number of comparisons done by a sortiong algorithm.*/
long long numcomparison(int i) {
    if (i == 1)
        return count_sel;
    else if (i == 2)
        return count_bubble;
    else if (i == 3)
        return count_quick;
    else if (i == 4)
        return count_merge;
}

/*This function generates an array filled with random numbers.*/
long *randarray(long n) {

    srand(time(0));
    long *arr = (long*)malloc(n * sizeof(long));
    
    for(int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return arr;
}

/*Function to swap two numbers.*/
void swap(long *xp, long *yp) 
{ 
    long temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 




void selectionSort(long arr[], long n) 
{ 
    long i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                count_sel++;    //Counting the number of comparisons
            }
        }
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
}




void bubbleSort(long arr[], long n) 
{ 
   long i, j; 
   for (i = 0; i < n-1; i++) {      
       // Last i elements are already in place    
        for (j = 0; j < n-i-1; j++) { 
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                count_bubble++;     //Counting the number of comparisons
            }
        }    
   }
} 




/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
long partition (long arr[], long low, long high) 
{ 
    long pivot = arr[high];    // pivot 
    long i = (low - 1);  // Index of smaller element 
  
    for (long j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]);
            count_quick++;      //Counting the number of comparisons
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(long arr[], long low, long high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        long pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 




void merge(long arr[], long l, long m, long r)
{
    long i, j, k;
    long n1 = m - l + 1;
    long n2 = r - m;
 
    /* create temp arrays */
    long *L = (long*)malloc(n1*sizeof(long)); 
    long *R = (long*)malloc(n2*sizeof(long));
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            count_merge++;      //Counting the number of comparisons
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(long arr[], long l, long r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}