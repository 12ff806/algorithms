/*
 * selection_sort.c
 * selection sort 
 * 在剩下的无序元素中不断找出最小元素，并将其放到已排序数组末尾
 * O(n^2)
 * number29
 * December 22, 2020
 */


#include <stdio.h>


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void selection_sort(int s[], int n)
{
    int i, j;
    int min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (s[j] < s[min]) {
                min = j;
            }
        }
        swap(&s[i], &s[min]);
    }
}


int main()
{
    int s[] = {3, 4, 1, 6, 7, 2, 9, 1, 0, 10};
    int len = sizeof(s) / sizeof(s[0]);
    selection_sort(s, len);

    for (int i=0; i < len; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    return 0;
}
