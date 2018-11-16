/* 
	SortingAlgorithms.cpp : Defines the entry point for the console application.
*/

#include "stdafx.h"
#include "IntroSortAlgorithm.h"
#include "HeapSortAlgorithm.h"
#include "QuickSortAlgorithm.h"
#include "MergeSortAlgorithm.h"

using namespace std;

// The sizes we will use for our arrays 
int smallValue	= 500000;  // 500 thousand 
int mediumValue = 5000000; // 5 million
int largeValue	= 100000000; // 100 million

// These arrays will be generated with random elements
int SmallRandomSortingArray[500000];
int MediumRandomSortingArray[5000000];
int LargeRandomSortingArray[100000000];

// These arrays will be generated half sorted
int SmallHalfSortedArray[500000];
int MediumHalfSortedArray[5000000];
int LargeHalfSortedArray[100000000];

// These arrays will be "almost" sorted, with only 50 elements at the end being unsorted
int SmallAlmostSortedArray[500000];
int MediumAlmostSortedArray[5000000];
int LargeAlmostSortedArray[100000000];

IntroSortAlgorithm A; 
HeapSortAlgorithm H;
QuickSortAlgorithm Q;
MergeSortAlgorithm M;


// Generates an array with random elements
void GenerateRandomArray(int n[], int num)
{
	for (int idx = 0; idx < num; idx++)
	{
		n[idx] = rand();
	}
}

// Generates a half sorted array
void GenerateHalfSortedArray(int n[], int num)
{
	// Build array sorted in ascending order until halfway through the array
	for (int idx = 0; idx < num / 2; idx++)
	{
		n[idx] = idx;
	}

	// The second half of the array will be random
	for (int idx = num / 2; idx < num; idx++)
	{
		n[idx] = rand();
	}
}

// Generates an almost sorted array
void GenerateAlmostSortedArray(int n[], int num)
{
	// Build array sorted in ascending order until 50 elemenets are left in the array 
	for (int idx = 0; idx < num - 50; idx++)
	{
		n[idx] = idx;
	}

	// Fill in the final 50 elements with random numbers
	for (int idx = num - 50; idx < num; idx++)
	{
		n[idx] = rand();
	}
}

// Prints an array
void PrintArray(int n[], int num)
{
	for (int idx = 0; idx < num; idx++)
	{
		cout << n[idx] << " ";
	}
}

// Generates the arrays necessary for us to test our sorting algorithms
void GenerateAllArrays()
{
	GenerateRandomArray(SmallRandomSortingArray, smallValue);
	GenerateRandomArray(MediumRandomSortingArray, mediumValue);
	GenerateRandomArray(LargeRandomSortingArray, largeValue);

	GenerateHalfSortedArray(SmallHalfSortedArray, smallValue);
	GenerateHalfSortedArray(MediumHalfSortedArray, mediumValue);
	GenerateHalfSortedArray(LargeHalfSortedArray, largeValue);

	GenerateAlmostSortedArray(SmallAlmostSortedArray, smallValue);
	GenerateAlmostSortedArray(MediumAlmostSortedArray, mediumValue);
	GenerateAlmostSortedArray(LargeAlmostSortedArray, largeValue);
}

// We will be using different functions for each
// call to introsort on the different algorithms,
// so-as to easily analyze them in Visual Studio's
// Performance Analyzer

// Sorts the random array passed in
void IntroSortRandom(int n[], int num)
{
	// Pass the array, the pointer to the first element and  
	// the pointer to the last element 
	A.Introsort(n, n, n + num - 1);
}

// Sorts the half sorted array passed in
void IntroSortHalfSorted(int n[], int num)
{
	// Pass the array, the pointer to the first element and  
	// the pointer to the last element 
	A.Introsort(n, n, n + num - 1);
}

// Sorts the almost sorted array passed in
void IntroSortAlmostSorted(int n[], int num)
{
	// Pass the array, the pointer to the first element and  
	// the pointer to the last element 
	A.Introsort(n, n, n + num - 1);
}

// Sorts the random array passed in
void HeapSortRandom(int n[], int num)
{
	H.heapSort(n, num);
}

// Sorts the half sorted array passed in
void HeapSortHalfSorted(int n[], int num)
{
	H.heapSort(n, num);
}

// Sorts the almost sorted array passed in
void HeapSortAlmostSorted(int n[], int num)
{
	H.heapSort(n, num);
}

//////////////////////*****************************************////////////////////// 
// Sorts the random array passed in
void QuickSortRandom(int n[], int num)
{
	Q.quickSort(n, 0, num - 1);
}

// Sorts the half sorted array passed in
void QuickSortHalfSorted(int n[], int num)
{
	Q.quickSort(n, 0, num - 1);
}

// Sorts the almost sorted array passed in
void QuickSortAlmostSorted(int n[], int num)
{
	Q.quickSort(n, 0, num - 1);
}
//////////////////////*****************************************//////////////////////
// Sorts the random array passed in
void MergeSortRandom(int n[], int num)
{
	M.mergeSort(n, 0, num - 1);
}

// Sorts the half sorted array passed in
void MergeSortHalfSorted(int n[], int num)
{
	M.mergeSort(n, 0, num - 1);
}

// Sorts the almost sorted array passed in
void MergeSortAlmostSorted(int n[], int num)
{
	M.mergeSort(n, 0, num - 1);
}
//////////////////////*****************************************//////////////////////



int main()
{
/*
///////////////////////////////// IntroSort section /////////////////////////////////////////////////////

	// Generate the arrays we need in order to sort them with introsort
	GenerateAllArrays();

	// Random arrays : Sorting with introsort
	cout << "Calling IntroSort on an array with random elements of length: " << smallValue << endl;
	IntroSortRandom(SmallRandomSortingArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling IntroSort on an array of random elements of length: " << mediumValue << endl;
	IntroSortRandom(MediumRandomSortingArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling IntroSort on an array of random elements of length: " << largeValue << endl;
	IntroSortRandom(LargeRandomSortingArray, largeValue);
	cout << "Done sorting" << endl;

	// Half sorted arrays : Sorting with introsort
	cout << "Calling IntroSort on a half sorted array of length: " << smallValue << endl;
	IntroSortHalfSorted(SmallHalfSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling IntroSort on a half sorted array of length: " << mediumValue << endl;
	IntroSortHalfSorted(MediumHalfSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling IntroSort on a half sorted array of length: " << largeValue << endl;
	IntroSortHalfSorted(LargeHalfSortedArray, largeValue);
	cout << "Done sorting" << endl;

	// Almost sorted arrays : Sorting with introsort
	cout << "Calling IntroSort on an almost sorted array of length: " << smallValue << endl;
	IntroSortAlmostSorted(SmallAlmostSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling IntroSort on an almost sorted array of length: " << mediumValue << endl;
	IntroSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling IntroSort on an almost sorted array of length: " << largeValue << endl;
	IntroSortAlmostSorted(LargeAlmostSortedArray, largeValue);
	cout << "Done sorting" << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////	
/////////////////////////////////////// HeapSort Section ///////////////////////////////////////////////////

	// Generate arrays in order to sort them with heapsort
	GenerateAllArrays();

	// Arrays of random elements : sorting with heapsort
	cout << "Calling HeapSort on an array of random elements of length: " << smallValue << endl;
	HeapSortRandom(SmallRandomSortingArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling HeapSort on an array of random elements of length: " << mediumValue << endl;
	HeapSortRandom(MediumRandomSortingArray, mediumValue);
	cout << "Calling HeapSort on an array of random elements of length: " << largeValue << endl;
	HeapSortRandom(LargeRandomSortingArray, largeValue);

	// Half sorted arrays : Sorting with heapsort 
	cout << "Calling HeapSort on a half sorted array of length: " << smallValue << endl;
	HeapSortHalfSorted(SmallHalfSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling HeapSort on a half sorted array of length: " << mediumValue << endl;
	HeapSortHalfSorted(MediumHalfSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling HeapSort on a half sorted array of length: " << largeValue << endl;
	HeapSortHalfSorted(LargeHalfSortedArray, largeValue);
	cout << "Done sorting" << endl;

	// Almost sorted arrays : Sorting with heapsort
	cout << "Calling HeapSort on an almost sorted array of length: " << smallValue << endl;
	HeapSortAlmostSorted(SmallAlmostSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling HeapSort on an almost sorted array of length: " << mediumValue << endl;
	HeapSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling HeapSort on an almost sorted array of length: " << largeValue << endl;
	HeapSortAlmostSorted(LargeAlmostSortedArray, largeValue);
	cout << "Done sorting" << endl;
	
///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// QuickSort //////////////////////////////////////////////////

	// Generate arrays in order to sort them with QuickSort
	GenerateAllArrays();

	// Arrays of random elements : sorting with QuickSort
	cout << "Calling QuickSort on an array of random elements of length: " << smallValue << endl;
	QuickSortRandom(SmallRandomSortingArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling QuickSort on an array of random elements of length: " << mediumValue << endl;
	QuickSortRandom(MediumRandomSortingArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling QuickSort on an array of random elements of length: " << largeValue << endl;
	QuickSortRandom(LargeRandomSortingArray, largeValue);

	// Half sorted arrays : Sorting with QuickSort
	cout << "Calling QuickSort on a half sorted array of length: " << smallValue << endl;
	QuickSortHalfSorted(SmallHalfSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling QuickSort on a half sorted array of length: " << mediumValue << endl;
	QuickSortHalfSorted(MediumHalfSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling QuickSort on a half sorted array of length: " << largeValue << endl;
	QuickSortHalfSorted(LargeHalfSortedArray, largeValue);
	cout << "Done sorting" << endl;

	// Almost sorted arrays : Sorting with QuickSort
	cout << "Calling QuickSort on an almost sorted array of length: " << smallValue << endl;
	QuickSortAlmostSorted(SmallAlmostSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling QuickSort on an almost sorted array of length: " << mediumValue << endl;
	QuickSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling QuickSort on an almost sorted array of length: " << largeValue << endl;
	QuickSortAlmostSorted(LargeAlmostSortedArray, largeValue);
	cout << "Done sorting" << endl;
	*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////// MergeSort //////////////////////////////////////////////////

	// Generate arrays in order to sort them with MergeSort
	GenerateAllArrays();

	// Arrays of random elements : sorting with MergeSort
	cout << "CallingMergeSort on an array of random elements of length: " << smallValue << endl;
	MergeSortRandom(SmallRandomSortingArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling MergeSort on an array of random elements of length: " << mediumValue << endl;
	MergeSortRandom(MediumRandomSortingArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling MergeSort on an array of random elements of length: " << largeValue << endl;
	MergeSortRandom(LargeRandomSortingArray, largeValue);

	// Half sorted arrays : Sorting with QuickSort
	cout << "Calling MergeSort on a half sorted array of length: " << smallValue << endl;
	MergeSortHalfSorted(SmallHalfSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling MergeSort on a half sorted array of length: " << mediumValue << endl;
	MergeSortHalfSorted(MediumHalfSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling MergeSort on a half sorted array of length: " << largeValue << endl;
	MergeSortHalfSorted(LargeHalfSortedArray, largeValue);
	cout << "Done sorting" << endl;

	// Almost sorted arrays : Sorting with QuickSort
	cout << "Calling MergeSort on an almost sorted array of length: " << smallValue << endl;
	MergeSortAlmostSorted(SmallAlmostSortedArray, smallValue);
	cout << "Done sorting" << endl;
	cout << "Calling MergeSort on an almost sorted array of length: " << mediumValue << endl;
	MergeSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
	cout << "Done sorting" << endl;
	cout << "Calling MergeSort on an almost sorted array of length: " << largeValue << endl;
	MergeSortAlmostSorted(LargeAlmostSortedArray, largeValue);
	cout << "Done sorting" << endl;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}

