#include <stdio.h>
#include <math.h>

/*

problem website
https://www.acmicpc.net/problem/9095

[Main Point]
HOW to count

[Solution]
Use recursive function
A[n] = A[n-1] + A[n-2] + A[n-3]

*/

int counting(int n);

int main() {
	int count, i;
	scanf("%d", &count);
	
	int num[count];
	
	for (i=0; i < count; ++i) {
		scanf("%d", &num[i]);
	}
	
	for (i=0; i < count; ++i) {
		printf("%d\n", counting(num[i]));
	}
	
	return 0;
}

int counting(int n) {
	int arr[11];
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	if (n < 4)
		return arr[n];
	
	int i;
	
	for (i=4; i <= n; ++i) {
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	}
	
	return arr[i-1];
}
