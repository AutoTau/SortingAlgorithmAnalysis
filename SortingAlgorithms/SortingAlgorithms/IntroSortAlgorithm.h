/*
	Header file for the IntroSort Algorithm class
*/

#pragma once
#include <algorithm>
#include <iostream>

class IntroSortAlgorithm
{

public:
	IntroSortAlgorithm();
	~IntroSortAlgorithm();
	
	void swapValue(int *a, int *b);
	void InsertionSort(int arr[], int *begin, int *end);
	void IntrosortUtil(int arr[], int * begin, int * end, int depthLimit);
	void Introsort(int arr[], int *begin, int *end);
	void printArray(int arr[], int n);
	
	int* Partition(int arr[], int low, int high);
	int* MedianOfThree(int * a, int * b, int * c);
};

