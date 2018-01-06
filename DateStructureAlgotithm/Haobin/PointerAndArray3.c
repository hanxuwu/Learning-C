/*

指针和一维数组
    一维数组名
            一维数组名


*/

// 确定一个一维数组需要几个参数

//数组名，个数
# include <stdio.h>

// f 函数可以输出任何一个一维数组的内容
void f(int * pArr){
    printf("%d\n", *pArr);
}

// f函数可以输出任何一个一维数组的内容
void g(int *pArr,int len){
    int i;
    for (i = 0; i < len; ++i)
        printf("%d ", *(pArr + i));
    printf("\n");
}

int main(void){

    int a[5] = {1, 2, 3, 4, 5};
    int b[6] = {-1, -2, -3, 4, 5, 6};
    int c[100] = {1, 99, 22, 33};

    f(a); // a是 int*
    g(a,5);
}