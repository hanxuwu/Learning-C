/*
        专题：
            动态内存分配
                    * 传统数组的缺点
                        1.数组长度必须事先制定，且只能是常整数，不能是变量
                            例子：
                                int a[5]; //ok
                                int len=5    int a[len]  //error

                        2. 传统形式定义的数组，该数组的内存程序员无法手动释放
                            数组一旦定义，系统为该数组分配的存储空间就会一直存在，除非数组所在的函数运行结束，数组空间才会被系统释放

                        3.数组长度一旦定义，其长度就不能再更改 
                        数组的长度不能再函数运行过程中动态的扩充或缩小。

                        4.A 函数定义的数组，在A函数运行期间可以被其他函数使用，
                         但A函数运行完毕之后，A函数中的数组将无法再被其他函数使用
                    
                    * 为什么需要动态内存
                        动态数组很好解决了传统数组的4个缺陷
                        传统数组也叫静态数组

                    * 动态内存分配举例——动态函数的构造

                    * 跨函数使用内存的问题

*/

# include <stdio.h>

void g(int * pArr,int len){
    pArr[2] = 88;
}

void f(void){

    int a[5] = {1, 2, 3, 4, 5};
    g(a, 5);
    printf("%d\n", a[2]);
}


int main(void){
    f();
    return 0;
}