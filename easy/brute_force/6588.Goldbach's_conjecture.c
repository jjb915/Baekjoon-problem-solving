#include <stdio.h>
#include <stdlib.h>

/*

problem website
https://www.acmicpc.net/problem/6588

This question's main points are
1. How do we derive the fact that the input number
 is divided into two prime numbers or not.
2. How do we find out specific number is prime number.

This is my solution to first question
1. Determine if both a and b are decimal, increasing a from 1 to the input/2. (b = input - a)

to secend question
2. use is_prime function
 if you want more information
 use this reference https://en.wikipedia.org/wiki/Primality_test
 and find pseudocode
 
*/

int is_prime(int n) {
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
		for (a=1; a <= input/2; ++a) {
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
