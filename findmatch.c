/*
 * findmatch.c
 * find match
 * number29
 * December 22, 2020
 */


#include <stdio.h>


int findmatch(char *p, int len_p, char *t, int len_t)
{
    int i, j;
    
    for (i = 0; i <= (len_t-len_p); i++) {
        j = 0;
        while ((j < len_p) && (t[i+j] == p[j])) {
            j = j + 1;
        }
        if (j == len_p) {
            return i;
        }
    }
    return -1;
}


int main()
{
    char *t = "aabaaaaaaaabbacccaaac";
    char *p = "abba";
    int len_t = 21;
    int len_p = 4;
    
    int r = findmatch(p, len_p, t, len_t);
    printf("%d\n", r);
    
    return 0;
}
