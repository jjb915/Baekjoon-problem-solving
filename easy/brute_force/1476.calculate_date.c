#include <stdio.h>

/*

problem website
https://www.acmicpc.net/problem/1476

[Main Points]
1. HOW do we find the fact that the Year's
 remainder is equal with three input numbers.
 
[Solution]
1. Increase e, s, m, year from 1 until e=E, s=S, m=M

*/

int main() {
	int E, S, M; // 15, 28, 19
	int e=1, s=1, m=1, year=1;
	scanf("%d %d %d", &E, &S, &M);
	
	while (1) {
		if (e==E && s==S && m==M) break;
		++e; ++s; ++m; ++year;
		if (e==16) e=1;
		if (s==29) s=1;
		if (m==20) m=1;
	}
	
	printf("%d", year);
	
	return 0;
}
