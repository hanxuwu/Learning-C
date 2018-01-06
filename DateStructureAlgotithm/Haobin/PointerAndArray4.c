/*

一定要明白 9行的pArr[3] 和 14,16 行的a[3] 是同一个变量

*/
# include <stdio.h>

// 更改元素中的数值
void f(int * pArr,int len){
    pArr[3] = 88;
}

// 输出数组中的所有元素
void g(int * pArr,int len){
    for (int i = 0; i < len;i++){
        printf("%d ", pArr[i]);
    
    }
}

int main(void){
    int a[6] = {1, 2, 3, 4, 5, 6};
    printf("%d\n",a[3]);  // output  4
    f(a, 6);
    printf("%d\n", a[3]);
    
    int c;
    printf("Please input c");
    scanf("%d", &c);
    printf("c is %d\n",c);

    g(a, 6);

    return 0;
}