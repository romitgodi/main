// Sorting_algorithms.cpp
// Author: Romit Godi
// Ref: http://www.mycodeschool.com/work-outs
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

#define SIZE 7

void printArray(int* testArray)
{
	std::cout << "Array: " << std::endl;

	for (int i = 0; i < SIZE; i++) {
		std::cout << " " << testArray[i];
	}
	std::cout << std::endl;
}

void swapFunction(int& leftElement, int& rightElement)
{
	int temp = 0;
	temp = leftElement;
	leftElement = rightElement;
	rightElement = temp;
}

void bubbleSort(int* testArray)
{
	int temp = 0, flag;
	for (int k = 0; k < SIZE - 1; k++) {
		flag = 0;
		for (int j = 0; j < SIZE - k - 1; j++) {
			if ((int*)testArray[j] > (int*)testArray[j + 1]) {
				swapFunction(testArray[j], testArray[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void selectionSort(int* testArray)
{
	int minElementIndex = 0, temp;
	for (int i = 0; i < SIZE - 1; i++) {
		minElementIndex = i;
		for (int j = i + 1; j < SIZE; j++) {
			if ((int*)testArray[j] < (int*)testArray[minElementIndex]) {
				minElementIndex = j;
			}
		}
		swapFunction(testArray[i], testArray[minElementIndex]);
	}
}

void insertionSort(int* testArray)
{
	int tempValue = 0, tempPos = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		tempValue = testArray[i];
		tempPos = i;
		while (tempPos > 0 && (int*)testArray[tempPos - 1] > (int*)testArray[i]) {
			testArray[tempPos] = testArray[tempPos - 1];
			tempPos = tempPos - 1;
		}
		testArray[tempPos] = tempValue;
	}
}

void mergeLRArray(int* leftArray, int sizeL, int* rightArray, int sizeR, int* testArray)
{	
	int i = 0, j = 0, k = 0;

	while (i < sizeL && j < sizeR)
	{
		if (leftArray[i] <= rightArray[j])
		{
			testArray[k] = leftArray[i];
			i++;
		}
		else
		{
			testArray[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while (i < sizeL)
	{
		testArray[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < sizeR)
	{
		testArray[k] = rightArray[j];
		j++;
		k++;
	}
}

void mergeSort(int* testArray, int arraySize)
{
	int n = 0, mid = 0, sizeL = 0, sizeR = 0;
	n = arraySize;
	if (n < 2)
	{
		return;
	}

	mid = n / 2;
	sizeL = mid;
	sizeR = n - mid;

	int* leftArray = new int[sizeL];
	int* rightArray = new int[sizeR];
	for (int i = 0; i < sizeL; i++)
	{
		leftArray[i] = testArray[i];
	}
	for (int i = sizeL; i < n; i++)
	{
		rightArray[i - sizeL] = testArray[i];
	}
	mergeSort(leftArray, sizeL);
	mergeSort(rightArray, sizeR);
	mergeLRArray(leftArray, sizeL, rightArray, sizeR, testArray);
	delete[] leftArray;
	delete[] rightArray;
}

int partitionArray(int* testArray, int startIndex, int endIndex)
{
	int temp = 0;
	int pivot = testArray[endIndex];
	int partitionIndex = startIndex;

	for (int i = startIndex; i < endIndex; i++)
	{
		if (testArray[i] <= pivot)
		{
			swapFunction(testArray[i], testArray[partitionIndex]);
			partitionIndex++;
		}
	}
	swapFunction(testArray[partitionIndex], testArray[endIndex]);
	return partitionIndex;
}

void quickSort(int* testArray, int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int partitionIndex = partitionArray(testArray, startIndex, endIndex);
		quickSort(testArray, startIndex, partitionIndex - 1);
		quickSort(testArray, partitionIndex + 1, endIndex);
	}
}

int main(int argc, const char* argv[])
{
	int testArray[SIZE];
	int key=0;

	for (int i = 0; i < SIZE; i++) {
		testArray[i] = rand() % 10;
	}

	printArray(testArray);

	std::cout << "1. Bubble sort" << std::endl;
	std::cout << "2. Selection sort" << std::endl;
	std::cout << "3. Insertion sort" << std::endl;
	std::cout << "4. Merge sort" << std::endl;
	std::cout << "5. Quick sort" << std::endl;
	std::cout << "6. Heap sort" << std::endl;
	std::cout << "Enter the sorting algorithm key: ";
	std::cin >> key;

	switch (key)
	{
	case 1:
		bubbleSort(testArray);
		break;
	case 2:
		selectionSort(testArray);
		break;
	case 3:
		insertionSort(testArray);
		break;
	case 4:
		mergeSort(testArray,SIZE);
		break;
	case 5:
		quickSort(testArray, 0, SIZE - 1);
		break;
	default:
		break;
	}
	
	printArray(testArray);

	return 0;
}

