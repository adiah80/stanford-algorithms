// Number of integers to be sorted = 100,000.
// Array stored in file "integer_array.txt".

#include<bits/stdc++.h>
using namespace std;

int* merge_sort(int* arr, int len);

long long int inversions = 0;

int main(){

	int len = 100000;
	int arr[len];

	ifstream file("integer_array.txt");

    if (file.is_open())
        for (int i = 0; i < len; ++i)
            file >> arr[i];
   
	int* ptr = merge_sort(arr, len);
	printf("\nNo of Inversions : %lld\n",inversions);
}

int* merge_sort(int* arr, int len) {
 
	if (len == 1) {
		// Base Case.
		return arr;
	} 

	else {

		int len1 = len - len/2;
		int len2 = len/2;

		int arr1[len1];
		int arr2[len2];

		for(int i=0; i<len1; i++)
			arr1[i] = arr[i];

		for(int i=0; i<len2; i++)
			arr2[i] = arr[i + len - len/2];

		int* arr1_sorted = merge_sort(arr1, len1);
		int* arr2_sorted = merge_sort(arr2, len2);

		// Merging the soorted arrays.
		int iter1 = 0;
		int iter2 = 0;

		for (int i=0; i<len; i++) {
			if (iter1 == len1) {
				// When List 1 has been iterated over.
				arr[i] = arr2_sorted[iter2];
				iter2++;
			} 

			else if (iter2 == len2) {
				// When List 2 has been iterated over.
				arr[i] = arr1_sorted[iter1];
				iter1++;
			} 

			else {
				if (arr1_sorted[iter1] < arr2_sorted[iter2]){
					// Adding integer from List 1
					arr[i] = arr1_sorted[iter1];
					iter1++;
				}

				else {
					// Adding integer from List 2
					arr[i] = arr2_sorted[iter2];
					inversions += len1 - iter1;
					iter2++;
				}
			}
		}

		return arr;
	}
}

