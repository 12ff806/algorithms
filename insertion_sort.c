/*
 * insertion_sort.c
 * insertion sort
 * number29
 * December 16 2020
 */


#include <stdio.h>


void swap(int *a, int *b)
{
    //printf("a = %d, b = %d\n", *a, *b);
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void insertion_sort_v1(int s[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        j = i;
        while((j > 0) && (s[j] < s[j-1])) {
            swap(&s[j], &s[j-1]);
            j = j - 1;
        }
    }
}


void insertion_sort_v2(int s[], int n)
{
    int i, j;
    int temp;
    for (i = 1; i < n; i++) {
        j = i;
        while((j > 0) && (s[j] < s[j-1])) {
            temp = s[j];
            s[j] = s[j-1];
            s[j-1] = temp;
            j = j - 1;
        }
    }
}


int main()
{
    int s[] = {12, 1, 3, 0, 11, 45, 21, 2};
    
    //insertion_sort_v1(s, sizeof(s)/sizeof(int));
    insertion_sort_v2(s, sizeof(s)/sizeof(int));
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    return 0;
}

