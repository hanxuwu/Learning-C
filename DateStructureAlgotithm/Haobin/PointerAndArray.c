 # include <stdio.h>

 int main(void){
    int *p; // 等价于  int *p,也等价于 int* p：
    int i = 5;
    char ch = 'A';

    p = &i; // *p  以p的内容 为地址的变量
    *p = 99;
    printf("*p=%d,i=%d", *p, i);
    return 0;
}