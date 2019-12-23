#include <stdio.h>

/*

problem website
https://www.acmicpc.net/problem/2309

This question's main points are
1. HOW to find 7 nums sum is 100 among 9 nums
2. HOW to sort 7 nums in ascending order

This is my solution to first question
1. Sum all 9 nums and find 2 nums which add is equal to sum-100
  If that two nums add is equal to sum-100,
  change that num to 100 and break

to secend question
2. just quick_sort
 if you want more information
 use this reference https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html

*/

void quick_sort(int *arr, int start, int end) {
	int left = start;
	int right = end;
	int pivot = arr[(left+right)/2];
	
	while (left <= right) {
		while (arr[left] < pivot) ++left;
		while (arr[right] > pivot) --right;
		if (left <= right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			++left;
			--right;
		}
	}
	
	if (start < right)
		quick_sort(arr, start, right);
	
	if (left < end)
		quick_sort(arr, left, end);
		
}

int main() {
	int arr[100], i, j;
	int sum=0;
	for (i=0; i<9; ++i) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (i=0; i<8; ++i) {
		for (j=i+1; j<9; ++j) {
			if (arr[i] + arr[j] == sum-100){
				arr[i] = arr[j] = 100;
				break;
			}
		}
		if (arr[i]==100)
			break;
	}
	quick_sort(arr, 0, 8);
	for (i=0; i<7; ++i)
		printf("%d\n", arr[i]);
	
	return 0;
}
