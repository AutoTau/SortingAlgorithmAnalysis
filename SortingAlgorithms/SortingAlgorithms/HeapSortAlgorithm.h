/*
	Header file for the HeapSortAlgorithm class
*/

#pragma once
class HeapSortAlgorithm
{
public:
	HeapSortAlgorithm();
	~HeapSortAlgorithm();
	void heapify(int arr[], int n, int i);
	void heapSort(int arr[], int n);
};

