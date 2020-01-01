#include <stdio.h>

/*

 problem website
 https://www.acmicpc.net/problem/10974
 
 This problem is similar to problem 10972
 Please refer to that problem 
 
*/

void swap(int *a, int *b);
void reverse(int *first, int *last);
int next_permutation(int *first, int *last);

int main() {
	int n, i;
	scanf("%d", &n);
	int arr[n];
	
	for (i=0; i<n; ++i) {
		arr[i] = i+1;
	}
	
	do {
		for (i=0; i<n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	} while (next_permutation(arr, arr+n));
	
	return 0;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
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
			swap(i,j);
			reverse(ii, last-1);
			return 1;
		}
		if (i == first) {
			reverse(first, last-1);
			return 0;
		}
	}
}
