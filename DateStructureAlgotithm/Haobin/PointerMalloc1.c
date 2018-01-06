# include <stdio.h>
# include <malloc.h>

int main(void){

    int i = 5; // 分配了4个字节 静态分配
    int *p = (int *)malloc(4);
    /*
    1. 要使用malloc函数，必须添加malloc.h这个头文件
    2. malloc 函数只有一个形参，并且形参是整型
    3. 4表示请求系统为本程序分配4个字节
    4. malloc 函数只能返回第一个字节的地址
    5. 7行分配了8个字节， p变量占4个字节，p所指向的内存也占4个字节
    6. p本身所占的内存是静态分配的，p所指向的内存是动态分配的
    */
    printf("%#X\n", p);
    *p = 5; //*p 本身就是一个int 变量,只不过*p这个整型变量的内存分配方式和11行和11行
    free(p);// free(p) 表示把p所指向的内存给释放掉  p本身的内存是静态的，不能由程序释放，由系统自动释放
    printf("%#X\n", p);
    printf("free the pointer\n");

    return 0;
}