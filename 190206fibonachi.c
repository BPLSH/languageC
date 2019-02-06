#include<stdio.h>
int fibonachi(int num) {
	int result;

	if (num == 0) {
		return 1;
	}
	result = num*fibonachi(num-1);
	return result;
}
int main(void) {
	int num;
	int result;

	printf("정수 입력:");
	scanf_s("%d", &num);
	result = fibonachi(num);
	printf("%d! = %d", num,result);
}
