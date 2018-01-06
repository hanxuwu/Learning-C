/*
如果 p 是个指针变量，则 p[i] 永远等于 *(p+1)
*/


/*
确定一个一维数组需要： 数组第一个元素的地址和数组的长度
*/

# include <stdio.h>

// 修改值
void f(int *pArr,int len){
    pArr[2] = 10; // pArr[2]==*(pArr+2)==*(a+2) == a[2]
}

// 输出数组所有元素
void out(int *pArr,int len){
    for (int i = 0; i < len;i++)
        printf("%d ",pArr[i]);
    printf("\n");
    
}

int main(void){

    int a[5] = {1, 2, 3, 4, 5};
    //f(a, 5);
    // = &a[2]; //error 因为 a是常量

    printf("%#X,%#X\n", a, &a[0]);
    out(a, 5);
    f(a, 5);
    out(a, 5);
}