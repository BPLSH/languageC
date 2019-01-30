#include<stdio.h>

/*
1.12월 31일인 경우 1월 1일
2. 1월 31일인경우 2월 1일
3. 1월 4일인경우 1월 5일
*/
void PrintTomorrow(int mon, int day) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	if (mon > 12 || mon < 1 || day > days[mon] || day < 1) {
		printf("잘못 입력하셨습니다. 날짜를 확인해주세요.");
	}
	else {
		day++;
		if (day > days[mon]) {
			day = 1;
			mon++;
			if (mon == 13) {
				mon = 1;
			}
		}
		printf("내일은 %d월 %d일 입니다.", mon, day);
	}
	
}
int main(void) {
	int mon, day;

	printf("오늘 날짜를 공백으로 구분하여 입력해주세요:");
	scanf_s("%d", &mon,sizeof(mon));
	scanf_s("%d", &day, sizeof(day));
	PrintTomorrow(mon, day);
	return 0;
}
