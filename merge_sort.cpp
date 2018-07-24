#include<bits/stdc++.h>
using namespace std;

int* merge_sort(int* arr, int len);

int main(){
	
	int arr[] = {4,5,6,3,0,7,2,1,9,8,10};
	int len = sizeof(arr)/sizeof(arr[0]);

	printf("\nBefore Sorting : \n");
	for (int i=0; i<len; i++)
		cout<<arr[i]<<' ';
	cout<<endl;

	int* ptr = merge_sort(arr, len);

	printf("\nAfter Sorting : \n");
	for (int i=0; i<len; i++)
		cout<<ptr[i]<<' ';
}

int* merge_sort(int* arr, int len){

	if (len == 1) {
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

		int iter1 = 0;
		int iter2 = 0;

		for (int i=0; i<len; i++) {
			if (iter1 == len1) {
				arr[i] = arr2_sorted[iter2];
				iter2++;
			} 

			else if (iter2 == len2) {
				arr[i] = arr1_sorted[iter1];
				iter1++;
			} 

			else {
				if (arr1_sorted[iter1] < arr2_sorted[iter2]){
					arr[i] = arr1_sorted[iter1];
					iter1++;
				}

				else {
					arr[i] = arr2_sorted[iter2];
					iter2++;
				}
			}
		}

		return arr;

	}
}
