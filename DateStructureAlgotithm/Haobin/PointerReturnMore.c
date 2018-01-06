/*

如何通过被调函数修改主调函数普通变量的值
1.实参必须为该普通变量的地址
2.形参必须为指针变量
3.在被调函数中通过
        *形参名 = 。。。。。
    的方式就可以修改主调函数相关变量的值


*/

# include <stdio.h>
int f(int,int);
void g(int *, int *);


int f(int i,int j){
    return 100;
}

void g(int *p,int *q){

    *p = 1;
    *q = 2;
}

// 如果没有指针f() 无法直接更改a，b的值,  只能用 return
// 不发送地址，形参无法改变实参的值
int main(void){
    int a = 3, b = 5;
    f(a,b); //
    printf("a=%d,b=%d\n", a, b);
    g(&a, &b);
    printf("a=%d,b=%d\n", a, b);
}