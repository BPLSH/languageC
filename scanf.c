  1 #include<stdio.h>
  2 int main(void){
  3     int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, cnt;
  4     char c;
  5     char enter;
  6
  7     printf("데이터를 입력하세요 : ");
  8     cnt = scanf("%d %d %d", &a1, &a2, &a3);
  9     //scanf("%c", &enter);
 10     printf("첫 번째 scanf()로 입력된 데이터 개수 : %d\n", cnt);
 11     cnt = scanf("%c %d %d", &c, &a4, &a5);
 12     printf("두 번째 scanf()로 입력된 데이터 개수 : %d\n", cnt);
 13     printf("a1 = %d, a2 = %d, a3 = %d\n", a1, a2, a3);
 14     printf("c = %c, a4 = %d, a5 = %d\n", c, a4, a5);
 15
 16     return 0;
 17 }
