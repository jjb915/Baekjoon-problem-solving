#include <stdio.h>

/* 

 problem website
 https://www.acmicpc.net/problem/10973
 
 This problem is similar to problem 10972
 Please refer to that problem 
 
*/

void swap(int *a, int *b);
void reverse(int *first, int *last);
int last_permutation(int *first, int *last);

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int i;
	for (i=0; i<n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	if (!last_permutation(arr, arr+n)) {
		printf("-1");
		return 0;
	}
	
	for (i=0; i<n; ++i) {
		printf("%d ", arr[i]);
	}
	
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

int last_permutation(int *first, int *last) {
	if (first == last) return 0;
	int *i = first;
	++i;
	
	if (i == last) return 0;
	i = last;
	--i;
	
	while (1) {
		int *ii = i;
		--i;
		if (*i > *ii) {
			int *j = last;
			while (*i <= *(--j));
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
