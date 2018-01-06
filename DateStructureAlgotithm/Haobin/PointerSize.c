/*
一个指针变量到底占几个字节
        预备知识：
            sizeof(数据类型)
            功能：返回值就是该数据类型所占的字节数
            例子：
                sizeof(int)=4,sizeof(char)
                sizeof(double)=8
        假设p指向char 类型变量  1个字节
        假设q指向int 类型变量  4个字节
        假设r指向 doublie 类型变量  8个字节
        pqr本身所占的字节数是否相等

*/

# include <stdio.h>

int main(void){

    char ch = 'A';
    int i = 99;
    double x = 66.6;
    char *p = &ch;
    int *q = &i;
    double *r = &x;

    printf("ch:%d,i:%d,x:%d\n", sizeof(ch), sizeof(i), sizeof(x));
    printf("p:%d,q:%d,r:%d", sizeof(p), sizeof(q), sizeof(r));
}