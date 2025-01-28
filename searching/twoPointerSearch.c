

/*
Problem Statement:
Given an array of distinct integers and a target sum, find all pairs of elements that sum up to the target sum.
*/

#include <stdio.h>
#include <stdlib.h>

void twoSumPairs(int *arr, int n, int target)
{
    int start = 0, end = n - 1;
    int isPairFound = 0;

    while (start < end)
    {
        if (arr[start] + arr[end] == target)
        {
            printf("[%d %d]\n", arr[start], arr[end]);
            isPairFound = 1;
            start++;
            end--;
        }
        else if (arr[start] + arr[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    if (!isPairFound)
    {
        printf("No pairs found\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the array with distinct numbers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);

    twoSumPairs(arr, n, target);

    return 0;
}