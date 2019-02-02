//bubblesort

#include <stdio.h>
#define max 100
int main(void) {
	int i, j,t, tmp, num;
	int arr[max] = { 0 };
	printf("개수를 입력하시오:");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("before sorting : ");
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < num-1; i++) {
		for (j = 0; j < num - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
			for (t = 0; t < num; t++) {
				printf("%d ", arr[t]);
			}
			printf("\n");
		}
		
	}
	return 0;
}
