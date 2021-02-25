//Function prototypes
#include <stdlib.h>
#include <time.h>
#include <string.h>

long *copyarr(long *src, long size);
void swap(long *xp, long *yp); 
long *randarray(long n); 
long long numcomparison(int i);

void selectionSort(long arr[], long n);

void bubbleSort(long arr[], long n);

long partition (long arr[], long low, long high);
void quickSort(long arr[], long low, long high);

void merge(long arr[], long l, long m, long r);
void mergeSort(long arr[], long l, long r);