/**************************************************************************


Implementation file for the HeapSortAlgorithm class.
Code was taken and adapted from : https://www.geeksforgeeks.org/quick-sort/
to be used in benchmarking and informal analysis.


**************************************************************************/


#include "stdafx.h"
#include <iostream>
#include "QuickSortAlgorithm.h"
#include <algorithm>

using namespace std;

//Default constructor
QuickSortAlgorithm::QuickSortAlgorithm()
{
}

//Default desctructor
QuickSortAlgorithm::~QuickSortAlgorithm()
{
}

// A utility function to swap two elements 
//void QuickSortAlgorithm::swap(int* a, int* b)
//{
//	int t = *a;
//	*a = *b;
//	*b = t;
//}

/* 
   This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot 
 */
int QuickSortAlgorithm::partition(int arr[], int low, int high)
{	int rando = low + rand() % (high - low);
	int pivot = arr[rando];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

/* 
  The main function that implements QuickSort
  arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index 
*/
void QuickSortAlgorithm::quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//pi is partitioning index, arr[p] is now
		//at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//void QuickSortAlgorithm::quickSort(int arr[], int left, int right) {
//
//	int i = left, j = right;
//
//	int tmp;
//
//	int pivot = arr[(left + right) / 2];
//
//
//
//	/* partition */
//
//	while (i <= j) {
//
//		while (arr[i] < pivot)
//
//			i++;
//
//		while (arr[j] > pivot)
//
//			j--;
//
//		if (i <= j) {
//
//			tmp = arr[i];
//
//			arr[i] = arr[j];
//
//			arr[j] = tmp;
//
//			i++;
//
//			j--;
//
//		}
//
//	};
//
//
//
//	/* recursion */
//
//	if (left < j)
//
//		quickSort(arr, left, j);
//
//	if (i < right)
//
//		quickSort(arr, i, right);
//
//}