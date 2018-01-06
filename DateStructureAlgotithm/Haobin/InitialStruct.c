/*
赋值初始化
    定义的同时可以整体赋值
    如果定义完之后，则只能单个赋值
去除结构体变量中的每一个成员
结构体变量的运算
结构体变量和结构体变量指针作为函数参数传递的问题
*/

# include <stdio.h>

struct Student{
    int age;
    float score;
    char sex;
};

int main(void){
    struct Student st = {80, 66.6, 'F'};

    struct Student st2;
    st2.age = 12;
    st2.score = 56.2;
    st2.sex = 'M'; //单引号！！

    //编译后就可以提示成员变量
    

    printf("%d %.1f %c", st2.age, st2.score, st2.sex);
}