# include <stdio.h>
# include <malloc.h>


// 修改*p的值
void f(int *q){
    //*p = 200; //error
    // q =200; // error q 为 int*
    // **q = 300; // error 只有指针变量前可以加 *
    *q = 200;
    //free(q); //加 free(q)就错了, q 存的是 p的地址   
}

int main(void){
    int *p = (int *)malloc(sizeof(int));// sizeof(int) 返回值是int 所占的字节数
    *p = 10;
    printf("%d\n", *p); // 10
    f(p);
    printf("%d", *p); //200
    return 0;
}

