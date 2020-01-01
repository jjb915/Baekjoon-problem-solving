#include <stdio.h>

/*

 problem website
 https://www.acmicpc.net/problem/10972
 
 [Main Point]
 1. How to find where the decending order
  is broken.
 2. How to find next permutation
 
 [Solution]
 1. just use if (a < b)
 2. I use algorithm g++ library code next_permutation()
 for more information visit here
 https://jeonggyun.tistory.com/110
 
*/
 
void swap(int *a, int *b);
void reverse(int *first, int *last);
int next_permutation(int *first, int *last);

int main() {
	int n, i;
	scanf("%d", &n);
	
	int arr[n];
	for (i=0; i<n; ++i) 
		scanf("%d", &arr[i]);	
	
	if (!next_permutation(arr, arr+n)) {
		printf("-1");
		return 0;
	}
	
	for (i=0; i<n; ++i) 
		printf("%d ", arr[i]);
	
	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int *first, int *last) {
	int i;
	for (i=0; i <= (last-first)/2; ++i) {
		swap((first+i), (last-i));
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
