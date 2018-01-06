/*
指针：
    表示一些复杂的数据结构
    快速的传递数据（时间短）
    使函数返回一个以上的值
    能直接访问硬件
    能够方便的处理字符串
    理解面向对象语言中引用的基础

    总结：指针是C语言的灵魂

    指针的分类
    1.基本类型指针
    2.指针和数组
    3.指针和函数
    4.指针和结构体 
    5.多级指针
*/

/*
指针的定义
        地址：
            内存单元的编号
            从零开始的非负整数
            范围: 4G   0--4g-1

                    控制线： 确定读写（数据传输方向）
                    数据线： 数据传输
                    地址线： 确定控制哪一个单元
        指针：
            指针就是地址，地址就是指针
            指针变量就是存放内存单元编号的变量，或者说指针变量就是存放地址的变量
            指针和指针变量是两个不同的概念
            但是要注意，通常我们叙述时会把指针变量简称为指针
            指针的本质就是一个操作受限的非负整数
*/

/*
基本类型的指针：

*/
# include <stdio.h>

int main(void){

    int *p;
    int i = 3;
    int j;
    p = &i;//p保存i地址，p指向i，*p==i
}









