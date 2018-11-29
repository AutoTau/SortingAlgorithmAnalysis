/*
	Header file for QuickSort Algorithm
*/


#pragma once
class QuickSortAlgorithm
{
public:
	//Provided Constructor
	QuickSortAlgorithm();
	
	int partition(int arr[], int low, int high);
	void quickSort(int arr[], int low, int high);
	//void swap(int* a, int* b);

	//Provided Destructor
	~QuickSortAlgorithm();
};

