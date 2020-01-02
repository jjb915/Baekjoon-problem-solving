#include <stdio.h>
#include <math.h>

void swap(int *a, int *b);
void reverse(int *first, int *last);
int next_permutation(int *first, int *last);
int cal_difference(int *arr, int n);
void quick_sort(int *arr, int start, int end);

int main() {
	int n;
	scanf("%d", &n);
	
	int arr[n];
	int i, max_sum = 0;
	
	for (i=0; i<n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	quick_sort(arr, 0, n-1);
/*
	for (i=0; i<n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
*/
	while(next_permutation(arr, arr+n)) {
	 	
		int dif = cal_difference(arr, n);
		if (max_sum < dif) {
			max_sum = dif;
		}
/*		
		for (i=0; i<n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
*/
	}
		
	printf("%d", max_sum);
	return 0;
	
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int *first, int *last) {
	int i;
	for (i=0; i <= (last-first)/2; ++i) {
		swap(first+i, last-i);
	}
}

int next_permutation(int *first, int *last) {
	if (first == last) return 0;
	int *i = first;
	++i;
	
	if (i == last) return 0;
	i = last;
	--i;
	
	while (1) {
		int *ii = i;
		--i;
		if (*i < *ii) {
			int *j = last;
			while (*i >= *(--j));
			swap(i, j);
			reverse(ii, last-1);
			return 1;
		}
		if (i == first) {
			reverse(first, last-1);
			return 0;
		}
	}
}

int cal_difference(int *arr, int n) {
	int i, sum = 0;
	for (i=0; i < n-1; ++i) {
		sum += abs(arr[i] - arr[i+1]);
	}
	return sum;
}

void quick_sort(int *arr, int start, int last) {
	int left = start;
	int right = last;
	int pivot = arr[(start+last)/2];
	
	while (left <= right) {
		while (pivot > arr[left]) ++left;
		while (pivot < arr[right]) --right;
		if (left <= right) {
			swap(arr+left, arr+right);
			++left;
			--right;
		}
	}
	if (left < last) {
		quick_sort(arr, left, last);
	}
	if (right > start) {
		quick_sort(arr, start, right);
	}
}
