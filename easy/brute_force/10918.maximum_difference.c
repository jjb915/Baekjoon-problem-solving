#include <stdio.h>
#include <math.h>
void maximum_difference(int *arr, int n);
int cal_difference(int *arr, int n);

int main() {
	int n;
	scanf("%d", &n);
	
	int arr[n];
	int i;
	for (i=0; i<n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	maximum_difference(arr, n);
	
	for (i=0; i<n; ++i) {
		printf("%d ", arr[i]);
	}
	
	printf("%d", cal_difference(arr, n));
	
	return 0;
}

void maximum_difference(int *arr, int n) {
	int max[n/2], min[n/2];
	int i, j, a, b;
	
	for (i=0; i < n/2; ++i) {
		max[i] = -100;
		min[i] = 100;
		
		for (j=0; j<n; ++j) {
			if ((max[i] < arr[j]) && (arr[j] <= 100)) {
				max[i] = arr[j];
				printf("max = %d\n", arr[j]);
				a=j;
			}
					
			if ((min[i] > arr[j]) && (arr[j] <= 100)) {
				min[i] = arr[j];
				printf("min = %d\n", arr[j]);
				b=j;
			}			
		}
		arr[a] = 101;
		arr[b] = 101;
	}
	
	for (i=0; i<n/2; ++i) {
		printf("max : %d, min %d\n", max[i], min[i]);
	}
	
	if (n%2 == 1) {
		int another;
		for (i=0; i<n; ++i) {
			if (arr[j] <= 100) {
				another = arr[j];
			}
		}
	}
	
	if (n%2 == 0) {
		for (i=0; i < n/2; ++i) {
			if (i%2 == 0) {
				arr[n/2+i] = max[i];
				arr[n/2-i-1] = min[i];
			} 
			else {
				arr[n/2+i] = min[i];
				arr[n/2-i-1] = max[i];
			}
		}
	}
}

int cal_difference(int *arr, int n) {
	int i, sum=0;
	for (i=0; i<n-1; ++i) {
		sum += abs(arr[i] - arr[i+1]);
	}
	return sum;
}
		
	
	
