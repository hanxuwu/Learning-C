/*

指针变量的运算
        指针变量不能相加，不能相乘，也不能相除
        如果两个指针变量指向的是同一块连续空间中的不同存储单元
        则这两个指针变量可以相减

*/





# include <stdio.h>

int main(void){
    int j = 5;
    int i = 10;
    int *p = &i;
    int *q = &j;// 相减无意义

    int a[5];
    p = &a[5];
    q = &a[1];
    printf("%d", p - q);
}
