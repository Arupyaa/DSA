/*
 * ART_SORT.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Arthur
 */


#include "ART_SORT.h"

void selectionSort(int* arr,int arrLen, int (*keySorter)(int,int))
{
	for(int i = 0; i<arrLen-1;i++)
	{
		int temp = 0;
		int key=i;
		for(int j = i+1; j<arrLen; j++)
		{
			if( keySorter( arr[key],arr[j]) )
				key = j;
		}
		//found key of number to be swapped

		temp = arr[i]; arr[i] = arr[key]; arr[key] = temp;
		//swapped two nums around
	}

}


void insertionSort(int* arr,int arrLen, int (*keySorter)(int,int))
{
	int temp =0;
	for(int i = 0, j= 0; i<arrLen-1; i++)
	{
		if(keySorter(arr[i],arr[i+1]))
		{
			temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
			j = i;
			while(j!= 0 && keySorter(arr[j-1],arr[j]))
			{
				temp = arr[j]; arr[j] = arr[j-1]; arr[j-1] = temp;
				j--;
			}
		}

	}
}
