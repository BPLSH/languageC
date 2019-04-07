  1 #include <stdio.h>
  2 int main(void){
  3     double x,y;
  4     int where;
  5
  6     printf("x좌표를 입력하시오 :");
  7     scanf("%lf", &x);
  8
  9     printf("y좌표를 입력하시오 :");
 10     scanf("%lf", &y);
 11
 12     where = ((x>0)?((y>0)?1:4):((y>0)?2:3));
 13     printf("\"%.2lf, %.2lf\"는 %d 사분면에 있습니다.", x, y, where);
 14
 15     return 0;
 16 }
