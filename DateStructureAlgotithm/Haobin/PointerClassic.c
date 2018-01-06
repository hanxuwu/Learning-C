# include <stdio.h>

void swap_1(int, int);
void swap_2(int *, int *);
void swap_3(int *, int *);


// 不能完成互换功能
void swap_1(int a, int b){
    int t;
    t = a;
    a = b;
    b = t;

    return;
}

// 不能完成互换功能
void swap_2(int *p,int*q){

    int *t; // 如果要互换p和q的值，则t必须是int *，不能是int，否则会出错

    t = p;
    p = q;
    q = t;  //互换了 p，q的值.    a,b 并没有变
}

// 可以完成互换
void swap_3(int *p,int *q){
    int t;// 如果要互换*p 和 *q的值，则t 必须定义成 int，不能定义成 int *，否则语法错误

    t = *p;
    *p = *q;
    *q = t;
}



int main(void){

    int a = 3;
    int b = 5;
    int t;

    swap_1(a, b); // a,b 为形参
    printf("a=%d,b=%d\n", a, b);//a,b 为主函数的值

    swap_2(&a, &b); //swap_2(a,b) 是错误的
    printf("a=%d,b=%d\n", a, b);//a,b 为主函数的值

    swap_3(&a, &b); 
    printf("a=%d,b=%d\n", a, b);

    return 0;
}