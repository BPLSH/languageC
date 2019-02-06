#include<stdio.h>
int SquareofSecond(int num) {
	int result;

	if (num == 0) {
		return 1;
	}
	result = 2*SquareofSecond(num-1);
	return result;
}
int main(void) {
	int num;
	int result;

	printf("정수 입력:");
	scanf_s("%d", &num);
	result = SquareofSecond(num);
	printf("2의 %d승은 %d", num,result);
}
