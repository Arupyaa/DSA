/*
 * main.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Arthur
 */

#include <stdio.h>
#include "ART_SORT.h"
#include "ART_Search.h"
#include "ART_Pattern.h"
#define testing

int arr1[] = { 32,-43,95,543,4,34 };

//543, 32,-43,95,4,34
//543,32, -43,95,4,34
//543,32,95, 32,4,34 -- 543,95,32,

void printArr(int* arr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr[i]);
}
int findLargerNumKey(int n1, int n2)
{
    if (n1 >= n2)
        return 0;
    else
        return 1;
}
int findsmallerNumKey(int n1, int n2)
{
    if (n1 <= n2)
        return 0;
    else
        return 1;
}

int powermodulu(int x, int y, int q)
{
    int n = 1;
    for (int i = 0; i < y; i++)
        n = (n * x) % q;
    return n;
}

int main()
{
#ifndef testing
    printArr(arr1, 6);
    printf("\n");
    insertionSort(arr1, 6, findsmallerNumKey);
    printArr(arr1, 6);
    printf("\n");
    int targetIndex = sentinelLinearSearch(arr1, 6, 95);
    if (targetIndex == -1)
        printf("target doesn't exist\n");
    else
        printf("target %d is at index %d", arr1[targetIndex], targetIndex);

    char txt[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";
    int patternIndex = 0;
    int startingPos = 0;

    printf("\n\n\n");
    printf("text is %s\n", txt);
    printf("pattern is %s\n", pattern);
    while (1)
    {
        patternIndex = KMPSearch(txt, 16, pattern, 4, startingPos);
        if (patternIndex == -1)
        {
            printf("\nbreaked\n"); break;
        }
        printf("pattern found at index %d\n", patternIndex);
        startingPos = patternIndex + 1;

    }
#endif //not testing
#ifdef testing
    int arr[] = {9,3,7,5,6,4,8,2,4};
    //int arr[] = { 9,3,7,5};
    printf("arr before sort:\n");
    printArr(arr, 9);
    //mergeSort(arr, 9, findsmallerNumKey);
    mergeSortRecursive(arr, 0, 9 - 1,findLargerNumKey);
    printf("arr after sort:\n");
    printArr(arr, 9);
#endif //testing
    char m[21];
    scanf("%s", m);
    return 0;
}
