//Driver code
#include "head.h"
#include <stdio.h>


int main() {
    long size_arr[] = {100000, 150000 ,200000, 250000, 300000, 350000, 400000, 450000, 500000, 550000, 600000, 650000, 700000, 750000, 800000, 850000, 900000, 950000, 1000000};
    FILE *fp1, *fp2, *fp_time, *fp_comp;

    fp_time = fopen("sizeVStime.csv", "a+");
    fprintf(fp_time, "Array Size,Selection,Bubble,Quick,Merge\n");

    fp_comp = fopen("sizeVScomparison.csv", "a+");
    fprintf(fp_comp, "Array Size,Selection,Bubble,Quick,Merge\n");

    for (int i = 0; i < 19; i++) {

        long MAX = size_arr[i];
        long *test_arr = randarray(MAX);

        long *arr_sel = copyarr(test_arr, MAX);
        long *arr_bubble = copyarr(test_arr, MAX);
        long *arr_quick = copyarr(test_arr, MAX);  
        long *arr_merge = copyarr(test_arr, MAX);

        //Selection Sort
        clock_t t_sel; 
        t_sel = clock(); 
        selectionSort(arr_sel, MAX);
        t_sel = clock() - t_sel; 
        double time_taken_sel = ((double)t_sel)/CLOCKS_PER_SEC;

        fp1 = fopen("select_time.txt", "a+");
        fprintf(fp1, "%ld : %lf\n", MAX, time_taken_sel);
        
        fp2 = fopen("select_comparison.txt", "a+");        
        fprintf(fp2, "%ld : %lld\n", MAX, numcomparison(1));
        fclose(fp1);
        fclose(fp2);

        
        //Bubble Sort
        clock_t t_bubble; 
        t_bubble = clock(); 
        bubbleSort(arr_bubble, MAX);
        t_bubble = clock() - t_bubble; 
        double time_taken_bubble = ((double)t_bubble)/CLOCKS_PER_SEC;

        fp1 = fopen("bubble_time.txt", "a+");
        fprintf(fp1, "%ld : %lf\n", MAX, time_taken_bubble);
        
        fp2 = fopen("bubble_comparison.txt", "a+");        
        fprintf(fp2, "%ld : %lld\n", MAX, numcomparison(2));
        fclose(fp1);
        fclose(fp2);


        //Quick Sort
        clock_t t_quick; 
        t_quick = clock(); 
        quickSort(arr_quick, 0, MAX-1);
        t_quick = clock() - t_quick; 
        double time_taken_quick = ((double)t_quick)/CLOCKS_PER_SEC;

        fp1 = fopen("quick_time.txt", "a+");
        fprintf(fp1, "%ld : %lf\n", MAX, time_taken_quick);
        
        fp2 = fopen("quick_comparison.txt", "a+");        
        fprintf(fp2, "%ld : %lld\n", MAX, numcomparison(3));
        fclose(fp1);
        fclose(fp2);

        //Merge Sort
        clock_t t_merge; 
        t_merge = clock(); 
        mergeSort(arr_merge, 0, MAX-1);
        t_merge = clock() - t_merge; 
        double time_taken_merge = ((double)t_merge)/CLOCKS_PER_SEC;

        fp1 = fopen("merge_time.txt", "a+");
        fprintf(fp1, "%ld : %lf\n", MAX, time_taken_merge);
        
        fp2 = fopen("merge_comparison.txt", "a+");        
        fprintf(fp2, "%ld : %lld\n", MAX, numcomparison(4));
        fclose(fp1);
        fclose(fp2);

        fprintf(fp_time, "%ld,%lf,%lf,%lf,%lf\n", MAX, time_taken_sel, time_taken_bubble, time_taken_quick, time_taken_merge);
        fprintf(fp_comp, "%ld,%lld,%lld,%lld,%lld\n", MAX, numcomparison(1), numcomparison(2), numcomparison(3), numcomparison(4));

        free(test_arr);
        free(arr_sel);
        free(arr_bubble);
        free(arr_quick);
        free(arr_merge);
    }
    fclose(fp_time);
    fclose(fp_comp);

}