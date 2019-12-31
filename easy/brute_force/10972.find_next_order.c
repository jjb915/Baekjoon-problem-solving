#include <stdio.h>

void swap(int *a, int *b);

int main() {
	int count, i;
	scanf("%d", &count);
	
	int arr[count];
	for (i=0; i<count; ++i) 
		scanf("%d", &arr[i]);
	
	for (i=count-1; i>0; --i) {
		if (arr[i] > arr[i-1]) {
			swap(&arr[i], &arr[i-1]);
			break;
		}
	}
	
	if (i == 0) {
		printf("-1");
		return 0;
	}
	
	for (i=0; i<count; ++i) 
		printf("%d ", arr[i]);
	
	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
