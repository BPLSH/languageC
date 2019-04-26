#include <stdio.h>
#include <stdlib.h>

int main(void){
  double result = 1.0;
  int num;
  int i = 0;
  
  printf("2^n program : ");
  scanf("%d", &num);
  
  if(num < 0){
    num = -num;
    i = 1;
  }
  for(int i = 0; i < num; i++){
    result *= 2;
  }
  if(i){
    result = 1.0/result;
  }
  printf("2^%d : = %f", i? -num : num, result);
  
  return 0;
}  
  
