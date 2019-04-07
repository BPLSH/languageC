  1 /*
  2  * 사용자로부터 초 단위의 시간을 받아서 몇 분 몇 초인지 계산하는 프로그램
  3  */
  4 #include<stdio.h>
  5 int main(void){
  6     int num1, num2, result;
  7     printf("정수를 입력하시오 :");
  8     scanf("%d", &num1);
  9     printf("정수를 입력하시오 :");
 10     scanf("%d", &num2);
 11
 12     printf("%d + %d = %d\n", num1, num2, result = num1 + num2);
 13     printf("%d - %d = %d\n", num1, num2, result = num1 - num2);
 14     printf("%d * %d = %d\n", num1, num2, result = num1 * num2);
 15     printf("%d / %d = %d\n", num1, num2, result = num1 / num2);
 16     printf("%d %% %d = %d\n", num1, num2, result = num1 % num2);
 17
 18     return 0;
 19
 20 }
