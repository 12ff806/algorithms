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

/*
 * O(n^2)
 */
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
    printf("\n");
    return res;
}


/*
 * O(n^2)
 */
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
    printf("\n");
    return res;
}


/*
 * O(nlogn)
 */
int length_of_lis_v3(int s[], int n)
{
    // top[0] 存储的值表示当最长递增子序列长度为1时的最小值
    int top[n];
    // piles 表示 top 数组实际存储元素个数 即为最长递增子序列的长度
    int piles = 0;

    for (int i = 0; i < n; i++) {
        // 要处理的元素
        int ele = s[i];

        int left = 0, right = piles;
        while (left < right) {
            int mid = (left + right) / 2;
            if (top[mid] > ele) {
                right = mid;
            }
            else if (top[mid] < ele) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        if (left == piles) {
            piles ++;
        }
        top[left] = ele;
    }
    return piles;
}


int main()
{
    int s[] = {10, 9, 2, 5, 3, 7, 101, 18, 19};
    int n = sizeof(s) / sizeof(int);
    //printf("n = %d\n", n);
    
    //int r = length_of_lis_v1(s, n);
    //int r = length_of_lis_v2(s, n);
    int r = length_of_lis_v3(s, n);

    printf("%d\n", r);
    return 0;
}

