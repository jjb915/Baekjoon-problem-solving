#include <stdio.h>

/*

problem website
https://www.acmicpc.net/problem/1476

[Main Points]
1. HOW do we find the fact that the Year's
 remainder is equal with three input numbers.
 
[Solution]
1. Increase Year while year-E, year-S, year-M
 are equal to input number.

*/
int main() {
	int E, S, M;
	
	scanf("%d %d %d", &E, &S, &M);
	
	int year=1;
	
	while(1) {
		int e = year-E;
		int s = year-S;
		int m = year-M;
		
		if (e%15 == 0 && s%28 == 0 && m%19 == 0)
			break;
		++year;
	}
	
	printf("%d", year);
	
	return 0;
}
