# include <stdio.h>
# include <malloc.h>

/*
动态内存 堆分配

*/

void f(int **q)
{
    *q = (int *)malloc(sizeof(int)); //sizeof(数据类型)返回值是该数据类型所占的字节
                                     //等价于p=(int *)malloc(sizeof(int));
    **q = 5;

}

int main(void){
    int *p;
    f(&p);
    printf("%d\n", *p);
    return 0;
}