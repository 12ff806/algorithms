/*
 * longest_increasing_subsequence.c
 * return length of the longest increasing subsequence
 * number29
 * December 16, 2020
 */


#include <stdio.h>


int max(int a, int b)
{
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int length_of_lis_v1(int s[], int n)
{
    int m, dp[n];
    for (m = 0; m < n; m++) {
        dp[m] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 0;
    for (int k = 0; k < n; k ++) {
        printf("%d ", dp[k]);
        res = max(res, dp[k]);
    }
    return res;
}


int length_of_lis_v2(int s[], int n)
{
    int m, dp[n];
    for (m = 0; m < n; m++) {
        dp[m] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j]) {
                if (dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                }
            }
        }
    }

    int res = 0;
    for (int k = 0; k < n; k ++) {
        printf("%d ", dp[k]);
        if (dp[k] > res) {
            res = dp[k];
        }
    }
    return res;
}


int main()
{
    int s[] = {10, 9, 2, 5, 3, 7, 101, 18, 19};
    int n = sizeof(s) / sizeof(int);
    printf("n = %d\n", n);
    
    //int r = length_of_lis_v1(s, n);
    int r = length_of_lis_v2(s, n);

    printf("\n%d\n", r);
    return 0;
}

