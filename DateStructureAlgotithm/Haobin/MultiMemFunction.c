# include <stdio.h>

/*

静态变量不能跨函数使用！！！

*/

void f(int **q){ //q是个指针变量，无论q是什么类型的指针变量，都只占4个字节
    int i = 5;
    //*q 等价于p ，q 和 **q都不等价于p
    //*q = i error 因为 *q = i，
    *q = &i;
}

int main(void){
    int *p;
    f(&p);
    printf("%d\n", *p);//本语句语法没有问题，但逻辑有问题
    return 0;
}

