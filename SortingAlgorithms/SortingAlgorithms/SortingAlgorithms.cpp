/* 
	SortingAlgorithms.cpp : Defines the entry point for the console application.
*/

#include "stdafx.h"
#include "IntroSortAlgorithm.h"
#include "HeapSortAlgorithm.h"
#include "QuickSortAlgorithm.h"
#include "MergeSortAlgorithm.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// The sizes we will use for our arrays 
int smallValue	= 1000000;  // 1 million 
int mediumValue = 10000000; // 10 million
int largeValue	= 100000000; // 100 million

// These arrays will be generated with random elements
int SmallRandomSortingArray[1000000];
int MediumRandomSortingArray[10000000];
int LargeRandomSortingArray[100000000];

// These arrays will be generated half sorted
int SmallHalfSortedArray[1000000];
int MediumHalfSortedArray[10000000];
int LargeHalfSortedArray[100000000];

// These arrays will be "almost" sorted, with only 50 elements at the end being unsorted
int SmallAlmostSortedArray[1000000];
int MediumAlmostSortedArray[10000000];
int LargeAlmostSortedArray[100000000];

// These arrays will be sorted in largest to smallest, Worst case
int SmallWorstArray[1000000];
int MediumWorstArray[10000000];
int LargeWorstArray[100000000];

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

// Generate the worst cast scenario of sorted in decending order.
void GenerateWorstCaseArray(int n[], int num)
{
	for (int idx = num; idx > 0; --idx)
	{
		n[num - idx] = idx;
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

	GenerateWorstCaseArray(SmallWorstArray, smallValue);
	GenerateWorstCaseArray(MediumWorstArray, mediumValue);
	GenerateWorstCaseArray(LargeWorstArray, largeValue);
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

void IntroSortWorstCase(int n[], int num)
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

//Sorting the worst case possible.
void HeapSortWorstCase(int n[], int num) {

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

//Sorting the worst case possible.
void QuickSortWorstCase(int n[], int num) {

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

//Sorting the worst case possible.
void MergeSortWorstCase(int n[], int num) {
	
	M.mergeSort(n, 0, num - 1);

}
//////////////////////*****************************************//////////////////////



int main()
{

///////////////////////////////// IntroSort section /////////////////////////////////////////////////////

	// Generate the arrays we need in order to sort them with introsort
	GenerateAllArrays();
	
	// Random arrays : Sorting with introsort
	cout << "Calling IntroSort on an array with random elements of length: " << smallValue << endl;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	IntroSortRandom(SmallRandomSortingArray, smallValue);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
//	
//	cout << "Calling IntroSort on an array of random elements of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortRandom(MediumRandomSortingArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling IntroSort on an array of random elements of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortRandom(LargeRandomSortingArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();	
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	// Half sorted arrays : Sorting with introsort
//	cout << "Calling IntroSort on a half sorted array of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortHalfSorted(SmallHalfSortedArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	cout << "Calling IntroSort on a half sorted array of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortHalfSorted(MediumHalfSortedArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	cout << "Calling IntroSort on a half sorted array of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortHalfSorted(LargeHalfSortedArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	// Almost sorted arrays : Sorting with introsort
//	cout << "Calling IntroSort on an almost sorted array of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortAlmostSorted(SmallAlmostSortedArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling IntroSort on an almost sorted array of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling IntroSort on an almost sorted array of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortAlmostSorted(LargeAlmostSortedArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	// Descending arrays : Sorting with IntroSort
//	cout << "Calling IntroSort on a descending sorted array of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortWorstCase(SmallAlmostSortedArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling IntroSort on a descending sorted array of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortWorstCase(MediumAlmostSortedArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling IntroSort on a descending sorted array of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	IntroSortWorstCase(LargeAlmostSortedArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////	
///////////////////////////////////////// HeapSort Section ///////////////////////////////////////////////////
//
//	// Generate arrays in order to sort them with heapsort
//	GenerateAllArrays();
//
//	// Arrays of random elements : sorting with heapsort
//	cout << "Calling HeapSort on an array of random elements of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortRandom(SmallRandomSortingArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling HeapSort on an array of random elements of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortRandom(MediumRandomSortingArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling HeapSort on an array of random elements of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortRandom(LargeRandomSortingArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	// Half sorted arrays : Sorting with heapsort 
//	cout << "Calling HeapSort on a half sorted array of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortHalfSorted(SmallHalfSortedArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	cout << "Calling HeapSort on a half sorted array of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortHalfSorted(MediumHalfSortedArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling HeapSort on a half sorted array of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortHalfSorted(LargeHalfSortedArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	// Almost sorted arrays : Sorting with heapsort
//	cout << "Calling HeapSort on an almost sorted array of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortAlmostSorted(SmallAlmostSortedArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling HeapSort on an almost sorted array of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling HeapSort on an almost sorted array of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortAlmostSorted(LargeAlmostSortedArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//	// Descending arrays : Sorting with HeapSort
//	cout << "Calling HeapSort on a descending sorted array of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortWorstCase(SmallAlmostSortedArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling HeapSort on a descending sorted array of length: " << mediumValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortWorstCase(MediumAlmostSortedArray, mediumValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
//	cout << "Calling HeapSort on a descending sorted array of length: " << largeValue << endl;
//	t1 = high_resolution_clock::now();
//	HeapSortWorstCase(LargeAlmostSortedArray, largeValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//
//
//	
/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// QuickSort //////////////////////////////////////////////////
//
//	// Generate arrays in order to sort them with QuickSort
//	GenerateAllArrays();
//
//	// Arrays of random elements : sorting with QuickSort
//	cout << "Calling QuickSort on an array of random elements of length: " << smallValue << endl;
//	t1 = high_resolution_clock::now();
//	QuickSortRandom(SmallRandomSortingArray, smallValue);
//	t2 = high_resolution_clock::now();
//	duration = duration_cast<milliseconds>(t2 - t1).count();
//	cout << "Done sorting" << endl;
//	cout << duration << endl;
//	
	//cout << "Calling QuickSort on an array of random elements of length: " << mediumValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortRandom(MediumRandomSortingArray, mediumValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;
	//
	//cout << "Calling QuickSort on an array of random elements of length: " << largeValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortRandom(LargeRandomSortingArray, largeValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;

	// Half sorted arrays : Sorting with QuickSort
	/*cout << "Calling QuickSort on a half sorted array of length: " << smallValue << endl;
	t1 = high_resolution_clock::now();
	QuickSortHalfSorted(SmallHalfSortedArray, smallValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;*/

	//cout << "Calling QuickSort on a half sorted array of length: " << mediumValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortHalfSorted(MediumHalfSortedArray, mediumValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;

	//cout << "Calling QuickSort on a half sorted array of length: " << largeValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortHalfSorted(LargeHalfSortedArray, largeValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;

	//// Almost sorted arrays : Sorting with QuickSort
	//cout << "Calling QuickSort on an almost sorted array of length: " << smallValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortAlmostSorted(SmallAlmostSortedArray, smallValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;

	//cout << "Calling QuickSort on an almost sorted array of length: " << mediumValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;

	//cout << "Calling QuickSort on an almost sorted array of length: " << largeValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortAlmostSorted(LargeAlmostSortedArray, largeValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;

	//// Descending arrays : Sorting with QuickSort
	//cout << "Calling QuickSort on a descending sorted array of length: " << smallValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortWorstCase(SmallAlmostSortedArray, smallValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;
	//
	//cout << "Calling QuickSort on a descending sorted array of length: " << mediumValue << endl;
	//t1 = high_resolution_clock::now();
	//QuickSortWorstCase(MediumAlmostSortedArray, mediumValue);
	//t2 = high_resolution_clock::now();
	//duration = duration_cast<milliseconds>(t2 - t1).count();
	//cout << "Done sorting" << endl;
	//cout << duration << endl;
	
	/*cout << "Calling QuickSort on a descending sorted array of length: " << largeValue << endl;
	t1 = high_resolution_clock::now();
	QuickSortWorstCase(LargeAlmostSortedArray, largeValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////// MergeSort //////////////////////////////////////////////////

	// Generate arrays in order to sort them with MergeSort
	GenerateAllArrays();

	// Arrays of random elements : sorting with MergeSort
	cout << "CallingMergeSort on an array of random elements of length: " << smallValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortRandom(SmallRandomSortingArray, smallValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
	
	cout << "Calling MergeSort on an array of random elements of length: " << mediumValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortRandom(MediumRandomSortingArray, mediumValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
	
	cout << "Calling MergeSort on an array of random elements of length: " << largeValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortRandom(LargeRandomSortingArray, largeValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;

	// Half sorted arrays : Sorting with MergeSort
	cout << "Calling MergeSort on a half sorted array of length: " << smallValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortHalfSorted(SmallHalfSortedArray, smallValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
	
	cout << "Calling MergeSort on a half sorted array of length: " << mediumValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortHalfSorted(MediumHalfSortedArray, mediumValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
	
	cout << "Calling MergeSort on a half sorted array of length: " << largeValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortHalfSorted(LargeHalfSortedArray, largeValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;

	// Almost sorted arrays : Sorting with MergeSort
	cout << "Calling MergeSort on an almost sorted array of length: " << smallValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortAlmostSorted(SmallAlmostSortedArray, smallValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
	
	cout << "Calling MergeSort on an almost sorted array of length: " << mediumValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortAlmostSorted(MediumAlmostSortedArray, mediumValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
	
	cout << "Calling MergeSort on an almost sorted array of length: " << largeValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortAlmostSorted(LargeAlmostSortedArray, largeValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;

	// Descending arrays : Sorting with MergeSort
	cout << "Calling MergeSort on a descending sorted array of length: " << smallValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortWorstCase(SmallAlmostSortedArray, smallValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;
	
	cout << "Calling MergeSort on a descending sorted array of length: " << mediumValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortWorstCase(MediumAlmostSortedArray, mediumValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;

	cout << "Calling MergeSort on a descending sorted array of length: " << largeValue << endl;
	t1 = high_resolution_clock::now();
	MergeSortWorstCase(LargeAlmostSortedArray, largeValue);
	t2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Done sorting" << endl;
	cout << duration << endl;	
	
	while (1)
	{
		int end;
		cout << "Waiting for user to end program" << endl;
		cout << "Please press 0 to end program" << endl;
		cin >> end;
		if (end == 0)
		{
			return 0;
		}
		else
			continue;
	}

    return 0;
}

