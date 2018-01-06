
// 常见错误！！
# include <stdio.h>

int main(void){

    int * p=NULL; //p 为局部变量
    int i = 5;
    *p = i; // ERROR!!! P中本来存有内存的垃圾！  常见错误1
    printf("%d\n", *p);
    return 0;
}