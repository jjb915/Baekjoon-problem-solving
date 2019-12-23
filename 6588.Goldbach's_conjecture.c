#include <stdio.h>
#include <stdlib.h>

int is_prime(n) {
	if (n <= 3)
		return n > 1;
	if (n%2 == 0 || n%3 == 0)
		return 0;
	int i = 5;
	while (i*i <= n) {
		if (n%i == 0 || n%(i+2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}

int main() {
	int *arr;	
	int i=-1, a, b;
	
	arr = (int *)malloc(sizeof(int *) * 1000000);
	
	do {
		++i;
		scanf("%d", &arr[i]);
	} while (arr[i]);
	
	int count = i;
	
	for (i=0; i < count; ++i) {
		int input = arr[i];
		for (a=0; a <= input/2; ++a) {
			b = input - a;
			if (is_prime(a) && is_prime(b)) {
				printf("%d = %d + %d\n", input, a, b);
				break;
			}
		}
		if (a == input/2 + 1)
			printf("Goldbach's conjecture is wrong.\n");
	}	
	return 0;
}
