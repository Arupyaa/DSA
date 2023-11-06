/*
 * ART_Search.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Arthur
 */

#include "ART_Search.h"

int binarySearchNumbers(int* arr,int len,int target )
{
	int index = (len-1)/2;
	int lowerBound = 0,upperBound = len-1;
	while((upperBound - lowerBound)>= 0)
	{
		if(arr[index] == target)
			return index;
		else if(arr[index]>target)
		{
			upperBound = index-1;
			index = lowerBound + ((upperBound - lowerBound) / 2);
		}
		else
		{
			lowerBound = index+1;
			index = lowerBound + ((upperBound - lowerBound) / 2);
		}
	}
	return -1;
}


int linearSearch(int* arr,int len,int target )
{
	for(int i = 0; i<len;i++)
	{
		if(arr[i] == target)
			return i;
	}
	return -1;
}


int sentinelLinearSearch(int* arr,int len,int target )
{
	int lastElement = arr[len-1];
	arr[len-1] = target;
	int i= 0;
	while(arr[i] != target)
		i++;

	arr[len-1] = lastElement;
	if( i<(len-1) || arr[len-1] == target  )
		return i;
	else
		return -1;
}
