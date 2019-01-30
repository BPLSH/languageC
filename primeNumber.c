#include<stdio.h>
#define RANGE 100
#define BOOL int
#define true 1
#define false 0

int main(void) {
	BOOL Prime[RANGE + 1];
	int i, j;
	//전부 소수로 가정한다.
	for (i = 0; i <= RANGE; i++)
		Prime[i] = true;
	for (i = 2; i <= RANGE; i++) {
		if (Prime[i]) {
			for (j = i*i; j<= RANGE;j += i) {
				Prime[j] = false;
			}
		}
	}
	for (i = 2; i <= RANGE; i++) {
		if (Prime[i])
			printf("%d ", i);
	}
}
