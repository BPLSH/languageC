#include <stdio.h>
//4로 나누어떨어지고, 100으로 나누어 떨어지지 않고
//400으로 나누어 떨어지면윤년

//12월 31 1월 1일 //끝
//1월 5일 1월 6일 //끝
//1월 31일 2월 1일 //끝 //윤년아님
//윤년 2월 28일 ->2월 29일
void Tomorrow(int y, int m, int d) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
		days[2] = 29; //윤년인 경우 2월 29일로 변경
	}
	if (y < 0 || m >12 || m < 1 || d > days[m] || d < 0) {
		printf("날짜를 잘못입력하셨습니다."); //날짜 이상시 출력
	}
	else {
		d++;
		if (d > days[m]) {
			m++;
			d = 1;
			if (m == 13) {
				y++;
				m = 1;
			}
			if (days[2] == 29) {
				if (m == 3 && d == 30) {
					d = 1;
				}
			}
		}	
		printf("내일은 %d년 %d월 %d일입니다.", y, m, d);
	}
}
int main(void) {
	int year, month, day;
	printf("년도 월 일을 입력하세요");
	scanf_s("%d", &year, sizeof(year));
	scanf_s("%d", &month, sizeof(month));
	scanf_s("%d", &day, sizeof(day));

	Tomorrow(year, month, day);
	return 0;
}
