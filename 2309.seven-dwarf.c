#include <stdio.h>

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
