/*
 * ART_SORT.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Arthur
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ART_SORT.h"

void selectionSort(int* arr, int arrLen, int (*keySorter)(int, int))
{
    for (int i = 0; i < arrLen - 1; i++)
    {
        int temp = 0;
        int key = i;
        for (int j = i + 1; j < arrLen; j++)
        {
            if (keySorter(arr[key], arr[j]))
                key = j;
        }
        //found key of number to be swapped

        temp = arr[i]; arr[i] = arr[key]; arr[key] = temp;
        //swapped two nums around
    }

}


void insertionSort(int* arr, int arrLen, int (*keySorter)(int, int))
{
    int temp = 0;
    for (int i = 0, j = 0; i < arrLen - 1; i++)
    {
        if (keySorter(arr[i], arr[i + 1]))
        {
            temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
            j = i;
            while (j != 0 && keySorter(arr[j - 1], arr[j]))
            {
                temp = arr[j]; arr[j] = arr[j - 1]; arr[j - 1] = temp;
                j--;
            }
        }

    }
}

void mergeSort(int* arr, int arrLen, int(*keySorter)(int, int))
{
    int* arr_t = (int*)malloc(arrLen * sizeof(int));
    int p_step = 1;
    int p = 1;

    for (; p <= ceil(log2(arrLen)); p++)
    {
        p_step *= 2;

        for (int n = 0; n < arrLen; n += p_step)
        {
            int i = n, j = n + p_step/2, k = n;
            if ((p-1) % 2 == 0)
            {
                //on even phases merge arr elements into arr_t
                while (i < (n + p_step / 2) && i < arrLen && j < (n + p_step) &&j<arrLen)
                {
                    arr_t[k++] = !keySorter(arr[i], arr[j]) ? arr[i++] : arr[j++];
                }

                for (; i < (n + p_step / 2) && i < arrLen; i++)
                    arr_t[k++] = arr[i];
                for (; j < (n + p_step) && j < arrLen; j++)
                    arr_t[k++] = arr[j];
            }
            else
            {
                //on odd phases merge arr_t elements into arr
                while (i < (n + p_step / 2) && i < arrLen && j < (n + p_step) && j < arrLen)
                {
                    arr[k++] = !keySorter(arr_t[i], arr_t[j]) ? arr_t[i++] : arr_t[j++];
                }

                for (; i < (n + p_step / 2) && i < arrLen; i++)
                    arr[k++] = arr_t[i];
                for (; j < (n + p_step) && j < arrLen; j++)
                    arr[k++] = arr_t[j];
            }


        }
    }

    if (arr_t != NULL && (p % 2) == 0)
        memcpy(arr, arr_t, arrLen*sizeof(int));
    free(arr_t);
}
