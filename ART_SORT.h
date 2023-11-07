/*
 * ART_SORT.h
 *
 *  Created on: Oct 19, 2023
 *      Author: Arthur
 */

#ifndef ART_SORT_H_
#define ART_SORT_H_

void selectionSort(int* arr,int arrLen, int (*keySorter)(int,int));

void insertionSort(int* arr,int arrLen, int (*keySorter)(int,int));

void mergeSort(int* arr, int arrLen, int (*keySorter)(int, int));

void mergeSortRecursive(int* arr, int startIndex, int endIndex, int(*keySorter)(int, int));

#endif /* ART_SORT_H_ */
